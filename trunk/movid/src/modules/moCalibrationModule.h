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


#ifndef MO_Calibration_MODULE_H
#define MO_Calibration_MODULE_H

#include <vector>
#include "../moDataStream.h"
#include "../moDataGenericContainer.h"
#include "../moModule.h"
#include "cv.h"

class moCalibrationModule : public moModule {
public:
	moCalibrationModule();
	virtual ~moCalibrationModule();
	virtual void guiFeedback(const std::string& type, double x, double y);
	virtual void guiBuild();
	
	void notifyData(moDataStream *stream);
	void update();
	
	void start();
	void stop();
	void buildScreenPoints();
	void resetCalibration();
	void calibrate();
	bool calibrated;
	void notifyTriangulate();
	
private:
	moDataStream *input;
	moDataStream *output;
	moDataGenericList blobs;
	bool retriangulate;
	void triangulate();
	unsigned int active_point;
	unsigned int last_id;
	unsigned int last_finished_id;
	int current_duration;
	moPoint *current_touch;
	std::vector<moPoint> surfacePoints;
//	std::map<CvSubdiv2DPoint*, moPoint> delaunayToSurface;
	std::map<CvSubdiv2DPoint*, moPoint> delaunayToScreen;
	CvRect rect;
	CvMemStorage* storage;
	CvSubdiv2D* subdiv;
	void transformPoints();
	
	MODULE_INTERNALS();
};

#endif
