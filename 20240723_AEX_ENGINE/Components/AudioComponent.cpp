#include "AudioComponent.h"
#include "AEEngine.h"
#include "AEAudio.h"
AudioComp::AudioComp()
{
	mGroup = AEAudioCreateGroup();
	mAudio = AEAudioLoadSound("");
	volume = 0.5f;
	pitch = 1;
}

AudioComp::AudioComp(GameObject* own)
{
	mGroup = AEAudioCreateGroup();
	mAudio = AEAudioLoadSound("");;
	volume = 0.5f;
	pitch = 1;


}

AudioComp::~AudioComp()
{
	//Manager<AudioComp>::getptr()->RemovePtr(this);
	AEAudioUnloadAudio(mAudio);
	AEAudioUnloadAudioGroup(mGroup);
}

void AudioComp::Update()
{
	//Do NOT Copy this

	//if (!Playing)
	//{
	//	Play();
	//}

	Play();

}

void AudioComp::SetAudio(std::string s)
{
	mAudio = AEAudioLoadMusic(s.c_str());
}

void AudioComp::Play()
{
	if (isplay == 1) {
		AEAudioPlay(mAudio, mGroup, volume, pitch, -1);
	}
	isplay = 2;	
	
}

//bool AudioComp::IsPlaying() const
//{
//	//return Playing;
//}
