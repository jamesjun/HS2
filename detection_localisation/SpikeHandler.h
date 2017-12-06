#ifndef SPIKEHANDLER_H
#define SPIKEHANDLER_H

#include "ProcessSpikes.h"

using namespace std;

void setInitialParameters(int _num_channels, int _num_recording_channels, int _spike_delay, int _spike_peak_duration, string file_name, \
						  int _noise_duration, float _noise_amp_percent, int* _masked_channels, int** _channel_positions, int** _neighbor_matrix, \
						  int _max_neighbors, int _inner_radius, bool _to_localize, int _cutout_start, int _cutout_end, int _maxsl);
void loadRawData(short* _raw_data, int _index_data, int _iterations, int _frames, int _additional_data);
void setLocalizationParameters(int _aGlobal, int** _baselines, int _index_baselines);
void addSpike(int channel, int frame, int amplitude);
void terminateSpikeHandler();
float channelsDist(int start_channel, int end_channel);

#endif
