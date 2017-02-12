#pragma once
#include <vector>

class mdi {
	int df; //delay factor
	int mlr; // media lost rate 
	mdi(int df, int mlr) {
		this->df = df;
		this->mlr = mlr;
	}
public:
	int getDf() {
		return this->df;
	}
	int getMlr() {
		return this->mlr;
	}
};

class pcap_data {
	std::vector<long> payload; //ts payload
	std::vector<int> arrvTime; //arrival time of every ip package which should contain serveral ts packets
	std::vector<long> pcr; //program clock reference 
	std::vector<int> pcr_ts_pass; //ts packets passed between two pcr
};

class Result {
	std::vector<mdi> res;
public:
	std::vector<mdi> getRes() {
		return this->res;
	}
};