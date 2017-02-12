#ifndef MDI_PROTOCOL_H_
#define MDI_PROTOCOL_H_

#ifdef WIN32
#include <winsock2.h>
#pragma comment(lib,"ws2_32")
#pragma warning(disable:4996)
#else
#include <arpa/inet.h>
#endif
#include "Stdint.h"

namespace mdi {
#define ETHER_ADDR_LEN 6 
	//Global Header 24 bytes
	struct pcap_file_header {
		uint32_t  magic;
		uint16_t version_major;
		uint16_t version_minor;
		int32_t thiszone;	/* gmt to local correction */
		uint32_t sigfigs;	/* accuracy of timestamps */
		uint32_t snaplen;	/* max length saved portion of each pkt */
		uint32_t linktype;	/* data link type (LINKTYPE_*) */
	};

	//Packet Header 16 bytes
	struct pcap_pkthdr {
		uint32_t ts_sec;         /* timestamp seconds */
		uint32_t ts_usec;        /* timestamp microseconds */
		uint32_t incl_len;       /* number of octets of packet saved in file */
		uint32_t orig_len;       /* actual length of packet */
	};

	//ethernet  14 bytes
	typedef struct ether_header
	{
		uint8_t ether_dhost[ETHER_ADDR_LEN];
		uint8_t ether_shost[ETHER_ADDR_LEN];
		uint16_t ether_type;
	}ETHeader_t;
	//IP header 20 bytes
	typedef struct ip
	{
		uint8_t Ver_HLen;
		uint8_t ip_tos;
		uint16_t ip_len;
		uint16_t ip_id;
		uint16_t ip_off;
		uint8_t ip_ttl;
		uint8_t ip_p;
		uint16_t ip_sum;
		uint32_t ip_src;
		uint32_t ip_dst;
	}IPHeader_t;


	//udp header 8 bytes
	typedef struct udphdr
	{
		uint16_t uh_sport;
		uint16_t uh_dport;
		uint16_t uh_ulen;
		uint16_t uh_sum;
	}UDPHeader_t;

	typedef struct ts_pat_program {
		unsigned program_number : 16;
		unsigned program_map_pid : 13;
	}ts_pat_program;

}  //namespace mdi
#endif


