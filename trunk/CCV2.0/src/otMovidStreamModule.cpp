#include "otMovidStreamModule.h"

otStreamModule :: otStreamModule() : moModule(MO_MODULE_INPUT)
{
    this->is_internal = true;
    this->input = new moDataStream("stream");
    this->output_buffer = NULL;
    this->properties["id"] = new moProperty(moModule::createId("WebStream"));
    this->properties["scale"] = new moProperty(1);
    this->declareInput(0, &this->input, new moDataStreamInfo(
               "stream", "IplImage,IplImage8", "Image to stream on webbrowser"));
    // FIXME: silence error message that's printed when a module in the web gui
    //  is clicked that doesn't output IplImages
}

void otStreamModule :: stop()
{
    if ( this->output_buffer != NULL ) {
        cvReleaseImage(&this->output_buffer);
        this->output_buffer = NULL;
    }
    moModule::stop();
}

void otStreamModule :: notifyData(moDataStream *source)
{
    IplImage* src = (IplImage*)(this->input->getData());
    if ( src == NULL )
        return;
    if ( this->output_buffer == NULL ||
        this->output_buffer->nChannels != src->nChannels ) {
        if ( this->output_buffer != NULL ) {
            cvReleaseImage(&this->output_buffer);
        }
        CvSize size = cvGetSize(src);
        size.width /= this->property("scale").asInteger();
        size.height /= this->property("scale").asInteger();
        this->output_buffer = cvCreateImage(size, src->depth, src->nChannels);
    }
    this->notifyUpdate();
}

bool otStreamModule :: copy()
{
    IplImage *src;
    if ( this->output_buffer == NULL || this->input == NULL )
        return false;
    this->input->lock();
    src = (IplImage*)(this->input->getData());
    if ( src == NULL || src->imageData == NULL ) {
        this->input->unlock();
        return false;
    }
    if ( this->output_buffer->nChannels != src->nChannels ) {
        this->input->unlock();
        return false;
    }
    if ( this->property("scale").asInteger() == 1 )
        cvCopy(src, this->output_buffer);
    else
        cvResize(src, this->output_buffer);
    cvCvtColor(this->output_buffer, this->output_buffer, CV_BGR2RGB);
    this->input->unlock();
    return true;
}

moModule *otStreamModule :: createModule()
{
     return new otStreamModule();
}

