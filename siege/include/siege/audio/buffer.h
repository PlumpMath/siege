#ifndef __SIEGE_AUDIO_BUFFER_H__
#define __SIEGE_AUDIO_BUFFER_H__

#include "../common.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/**
    \brief Audio buffer

    The buffer holds the audio data for the \ref SGSource "sources" to play. Please note that a single buffer can be used in multiple sources.
*/
typedef struct SGBuffer
{
    /**
        \private
        \brief Internal handle

        \warning
            For internal use only.
    */
    void* handle;
} SGBuffer;

SGbool SG_EXPORT _sgBufferInit(void);
SGbool SG_EXPORT _sgBufferDeinit(void);

// @{
/**
    \memberof SGBuffer
    \brief Create an audio buffer
    \param fname Filename of the audio file to load
    \return The newly created buffer if successful, NULL otherwise.
*/
SGBuffer* SG_EXPORT sgBufferCreate(char* fname);
/**
    \memberof SGBuffer
    \brief Destroy an audio buffer
    \param buffer The buffer to destroy. It should not be used anymore after this call.
*/
void SG_EXPORT sgBufferDestroy(SGBuffer* buffer);
// @}

// @{
/**
    \memberof SGBuffer
    \brief Set the data of an audio buffer
    \param buffer The buffer of which the data should be modified
    \param channels The number of channels in the data
    \param format The audio format
    \param frequency The frequency (sample rate) of the data
    \param data Audio data to pass to the buffer
    \param datalen Length of the audio data in bytes
*/
void SG_EXPORT sgBufferSetData(SGBuffer* buffer, SGuint channels, SGuint format, SGuint frequency, void* data, SGuint datalen);
// @}

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __SIEGE_AUDIO_BUFFER_H__