//
//  ofxAudioDecoderTonic.h
//  ofxAudioDecoder
//
//  Created by Elias Zananiri on 2015-04-23.
//
//

#pragma once

#include "ofMain.h"
#include "ofxAudioDecoder.h"
#include "SampleTable.h" // Tonic

static Tonic::SampleTable ofxAudioDecoderTonic(ofxAudioDecoder& audioDecoder)
{
    Tonic::SampleTable sampleTable = Tonic::SampleTable(audioDecoder.getNumFrames(), audioDecoder.getChannels());
    memcpy(sampleTable.dataPointer(), audioDecoder.getRawSamples().data(), audioDecoder.getNumSamples() * sizeof(float));
    return sampleTable;
}

static Tonic::SampleTable ofxAudioDecoderTonic(const string& path)
{
    ofxAudioDecoder audioDecoder;
    audioDecoder.load(path);
    return ofxAudioDecoderTonic(audioDecoder);
}
