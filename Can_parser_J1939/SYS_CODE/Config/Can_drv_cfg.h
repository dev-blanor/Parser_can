/*
 * Can_drv.h
 *
 *  Created on: 01.12.2016
 *      Author: Semenov
 */

#ifndef CAN_DRV_H_
#define CAN_DRV_H_

#define CAN_NODE0_USED          (1)
#define CAN_NODE1_USED          (0)
#define CAN_NODE2_USED          (0)
#define CAN_NODE3_USED          (0)
#define CAN_NODE4_USED          (0)
#define CAN_NODE5_USED          (0)

#define CAN_NODE_FOR_CCP        (0)

#define MO_NODE2_IN             99
#define MO_NODE2_OUT            100
#define MO_NODE0_IN             97
#define MO_NODE0_OUT            98
#define MO_NODE1_IN             8
#define MO_NODE1_OUT            9
#define MO_CCP_OUT0             8
#define MO_CCP_OUT1             9

// Number of used CAN Nodes
#define CAN_NUM_NODE_USED  (CAN_NODE0_USED + CAN_NODE1_USED + CAN_NODE2_USED + CAN_NODE3_USED)

#endif /* CAN_DRV_H_ */
