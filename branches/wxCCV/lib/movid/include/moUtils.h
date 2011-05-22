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


#ifndef MO_UTILS_H
#define MO_UTILS_H

#include <string>
#include <vector>

#define PI 3.14159265

class moUtils {
public:
	static std::vector<std::string> tokenize(const std::string& str, const std::string& delimiters);
	static double time();
	static bool inList(const std::string &pattern, const std::string &str, const std::string &delimiters = ",");
	static double degToRad(double deg);
	static double radToDeg(double rad);
};

#endif
