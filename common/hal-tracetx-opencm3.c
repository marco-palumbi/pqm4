#include <stdint.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/dma.h>
#include <libopencm3/stm32/rcc.h>


/*--------------------------------------------------------------------*/
void tracetx_dma_setup(void)
{
	/* USART2 uses DMA controller 1 Stream 6 Channel 4. */
	/* Enable DMA1 clock and IRQ */
	rcc_periph_clock_enable(RCC_DMA1);
	// nvic_enable_irq(NVIC_DMA1_STREAM6_IRQ);

	dma_stream_reset(DMA1, DMA_STREAM6);
	dma_set_priority(DMA1, DMA_STREAM6, DMA_SxCR_PL_LOW);
	dma_set_memory_size(DMA1, DMA_STREAM6, DMA_SxCR_MSIZE_8BIT);
	dma_set_peripheral_size(DMA1, DMA_STREAM6, DMA_SxCR_PSIZE_8BIT);
	dma_enable_memory_increment_mode(DMA1, DMA_STREAM6);
	// dma_enable_circular_mode(DMA1, DMA_STREAM6);
	dma_set_transfer_mode(DMA1, DMA_STREAM6,
				DMA_SxCR_DIR_MEM_TO_PERIPHERAL);
	dma_set_peripheral_address(DMA1, DMA_STREAM6, (uint32_t) &(USART_DR(USART2)));

	// dma_set_memory_address(DMA1, DMA_STREAM6, (uint32_t) NULL);
	dma_set_number_of_data(DMA1, DMA_STREAM6, 0);
	// dma_enable_transfer_complete_interrupt(DMA1, DMA_STREAM6);
	dma_channel_select(DMA1, DMA_STREAM6, DMA_SxCR_CHSEL_4);
	usart_enable_tx_dma(USART2);
}


/*--------------------------------------------------------------------*/
/* The ISR simply provides a test output for a CRO trigger */

// void dma1_stream6_isr(void)
// {
// 	if (dma_get_interrupt_flag(DMA1, DMA_STREAM6, DMA_TCIF)) {
// 		dma_clear_interrupt_flags(DMA1, DMA_STREAM6, DMA_TCIF);
// 		/* Toggle PC1 just to keep aware of activity and frequency. */
// 		gpio_toggle(GPIOC, GPIO1);
// 	}
// }

void tracetx_set_lenght(uint16_t number)
{
	dma_set_number_of_data(DMA1, DMA_STREAM6, number);
}

void tracetx_start(void *txbuffer)
{
	dma_set_memory_address(DMA1, DMA_STREAM6, (uint32_t) txbuffer);
	dma_enable_stream(DMA1, DMA_STREAM6);
}

void tracetx_wait(void)
{
	// busy wait for DMA transfer complete
	while(!dma_get_interrupt_flag(DMA1, DMA_STREAM6, DMA_TCIF));
	dma_clear_interrupt_flags(DMA1, DMA_STREAM6, DMA_TCIF);
}

