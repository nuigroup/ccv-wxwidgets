#ifndef _OTSTEAMMODULE_H
#define _OTSTEAMMODULE_H

#include <string>
#include <moDaemon.h>
#include <moPipeline.h>
#include <moFactory.h>
#include <moDataStream.h>
#include <cv.h>

class otStreamModule : public moModule
{
public:
    otStreamModule();
    void stop();
    void notifyData(moDataStream *source);
    bool copy();
    virtual void update() {}
    virtual std::string getName() { return "Stream"; }
    virtual std::string getDescription() { return ""; }
    virtual std::string getAuthor() { return ""; }

    moDataStream *input;
    IplImage* output_buffer;
};

#endif // _OTSTEAMMODULE_H
