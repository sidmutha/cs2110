/*
 * packet.h
 *
 *  Created on: 12-Aug-2012
 *      Author: sid
 */

#ifndef PACKET_H_
#define PACKET_H_

typedef struct {
	char sender[10], receiver[10], message[30];
} packet;

#endif /* PACKET_H_ */
