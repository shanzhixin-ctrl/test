#include "./BSP/IC/ic.h"

CAN_HandleTypeDef can;         


void can_init(void)
{

    can.Instance = CAN1;
    can.Init.Mode                 = CAN_MODE_LOOPBACK;
    can.Init.Prescaler            = 4;
    can.Init.SyncJumpWidth        = CAN_SJW_1TQ;
    can.Init.TimeSeg1             = CAN_BS1_14TQ;
    can.Init.TimeSeg2             = CAN_BS2_3TQ;

    
    can.Init.TimeTriggeredMode    = DISABLE;
    can.Init.AutoBusOff           = ENABLE;
    can.Init.AutoWakeUp           = DISABLE;
    can.Init.AutoRetransmission   = ENABLE;
    can.Init.ReceiveFifoLocked    = DISABLE;
    can.Init.TransmitFifoPriority = DISABLE;

    HAL_CAN_Init(&can);


    {
        CAN_FilterTypeDef filter = {0};

        filter.FilterBank           = 0;
        filter.FilterMode           = CAN_FILTERMODE_IDMASK;
        filter.FilterScale          = CAN_FILTERSCALE_16BIT;
        filter.FilterFIFOAssignment = CAN_FilterFIFO0;
        filter.FilterActivation     = ENABLE;
        filter.SlaveStartFilterBank = 14;
        filter.FilterIdLow      = (uint32_t)(0x123U << 5);
        filter.FilterMaskIdLow  = (uint32_t)((0x7FFU << 5) | 0x10U);

        filter.FilterIdHigh     = (uint32_t)(0x123U << 5);
        filter.FilterMaskIdHigh = (uint32_t)((0x7FFU << 5) | 0x10U);

        HAL_CAN_ConfigFilter(&can, &filter);
    }

    HAL_CAN_Start(&can);
}

void HAL_CAN_MspInit(CAN_HandleTypeDef *hcan)
{
if(hcan->Instance==CAN1)
{
__HAL_RCC_CAN1_CLK_ENABLE();
__HAL_RCC_GPIOA_CLK_ENABLE ();
	
	GPIO_InitTypeDef gpio;
	gpio.Mode =GPIO_MODE_AF_PP;
	gpio.Pin =GPIO_PIN_12;
	gpio.Pull=GPIO_PULLUP;
	gpio.Speed=GPIO_SPEED_FREQ_HIGH ;
	HAL_GPIO_Init(GPIOA,&gpio);
	gpio.Pin=GPIO_PIN_11;
	gpio.Mode =GPIO_MODE_AF_INPUT ;
	HAL_GPIO_Init(GPIOA,&gpio);

}

}


void can_tx(uint8_t buf[1])
{
CAN_TxHeaderTypeDef tx = {0};
	tx.DLC =1;
	tx.IDE =CAN_ID_STD ;
	tx.StdId =0x123;
buf[0]=1;
	tx.RTR =CAN_RTR_DATA ;


uint32_t mail = 0;
HAL_CAN_AddTxMessage (&can,&tx,buf,&mail);


}


void can_rx(uint8_t huf[1])
{
	CAN_RxHeaderTypeDef rx;
	uint8_t i;

	for (i = 0; i < 5; i++)
	{
		if (HAL_CAN_GetRxMessage(&can, CAN_RX_FIFO0, &rx, huf) == HAL_OK)
		{
			return;
		}
		HAL_Delay(1);
	}
}
