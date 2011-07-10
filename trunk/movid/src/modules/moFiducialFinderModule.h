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


#ifndef MO_FIDUCIAL_FINDER_MODULE_H
#define MO_FIDUCIAL_FINDER_MODULE_H

#include "../moDataGenericContainer.h"
#include "../moUtils.h"
#include "moImageFilterModule.h"

#define MAX_FIDUCIALS 512

class moFiducialFinderModule : public moImageFilterModule {
public:
	moFiducialFinderModule();
	virtual ~moFiducialFinderModule();
	
protected:
	moDataGenericList fiducials;
	moDataStream *output_data;
	
	void applyFilter(IplImage*);
	void allocateBuffers();
	void clearFiducials();

	void *internal;

	MODULE_INTERNALS();
};

#endif

