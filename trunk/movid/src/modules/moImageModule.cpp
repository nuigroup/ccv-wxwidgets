/***********************************************************************
 ** Copyright (C) 2010 Movid Authors.  All rights reserved.
 **
 ** This file is part of the Movid Software.
 **
 ** This file may be distributed under the terms of the Q Public License
 ** as defined by Trolltech AS of Norway and appearing in the file
 ** LICENSE included in the packaging of this file.
 **
 ** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 ** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 **
 ** Contact info@movid.org if any conditions of this licensing are
 ** not clear to you.
 **
 **********************************************************************/


#include <assert.h>

#include "../moLog.h"
#include "../moModule.h"
#include "../moDataStream.h"
#include "moImageModule.h"
#include "highgui.h"

MODULE_DECLARE(Image, "native", "Use a static image as source");

void fileChangedCallback(moProperty *prop, void *_inst) {
	moImageModule *inst = static_cast<moImageModule*> (_inst);
	inst->reloadImage();
}

moImageModule::moImageModule() : moModule(MO_MODULE_OUTPUT) {

	MODULE_INIT();

	this->image = NULL;
	this->stream = new moDataStream("IplImage");

	// declare outputs
	this->declareOutput(0, &this->stream, new moDataStreamInfo(
			"image", "IplImage", "Image stream on a static image"));

	// declare properties
	this->properties["filename"] = new moProperty("");
	this->properties["filename"]->addCallback(fileChangedCallback, this);
}

moImageModule::~moImageModule() {
}

void moImageModule::reloadImage() {
	if (this->image != NULL) {
		cvReleaseImage(&(this->image));
		this->image = NULL;
	}
	this->image = cvLoadImage(this->property("filename").asString().c_str());
	if ( this->image == NULL ) {
		LOGM(MO_ERROR, "could not load image: " << this->property("filename").asString());
		this->setError("unable to load image");
	}
	else {
		this->notifyUpdate();
	}
}

void moImageModule::start() {
	if ( this->image != NULL )
		this->stop();

	moModule::start();
	this->reloadImage();
}

void moImageModule::stop() {
	moModule::stop();
	if ( this->image != NULL ) {
		LOGM(MO_TRACE, "release Image");
		cvReleaseImage(&(this->image));
		this->image = NULL;
	}
}

void moImageModule::update() {
	if ( this->image != NULL ) {
		// push a new image on the stream
		LOGM(MO_TRACE, "push a new image on the stream");
		this->stream->push(this->image);
	}
}

