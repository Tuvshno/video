#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>

int main(int argc, char *argv[]) {
    AVFormatContext *pFormatCtx = NULL;

    // Open the file
    if(avformat_open_input(&pFormatCtx, argv[1], NULL, NULL) != 0) {
        return -1;
    }

    // Find stream information
    if(avformat_find_stream_info(pFormatCtx, NULL) < 0) {
        return -1;
    }

    // Dump information about the file
    av_dump_format(pFormatCtx, 0, argv[1], 0);

    int i;
    AVCodecContext *pCodecCtxOrig = NULL;
    AVCodecContext *pCodecCtx = NULL;

    // Find first video stream
    int videoStream = -1;
    for (int i = 0; i < pFormatCtx->nb_streams; i++) {
        if(pFormatCtx->streams[i]->codecpar->codec_type==AVMEDIA_TYPE_VIDEO) {
            videoStream=i;
            break;
        }
    }

    if (videoStream == -1) {
        return -1;
    }

    // Get a pointer to the codec context for the video stream
    pCodecCtx = pFormatCtx->streams[videoStream]->codecpar;

    AVCodec *pCodec = NULL;

    //Find the decoder for the video stream
    pCodec = avcodec_find_decoder(pCodecCtx->codec_id);
    if (pCodec == NULL) {
        fprintf(stderr, "Unsupported codec!\n");
        return -1;
    }

    // Copy context
    pCodecCtx = avcodec_alloc_context3(pCodec);
    if(avcodec_parameters_copy(pCodecCtx, pCodecCtxOrig) != 0) {
        fprintf(stderr, "Couldn't copy codec context");
        return -1;
    }

    // Open Codec
    if(avcodec_open2(pCodecCtx, pCodec, NULL) < 0) {
        return -1;
    }

    // AVFrame *pFrame = NULL;

    // Allocate video frame
    // pFrame = av_frame_alloc();


}



