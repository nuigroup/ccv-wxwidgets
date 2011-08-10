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

#include "moUtils.h"

#ifdef _WIN32
#include <windows.h>
#else // _WIN32
#include <sys/time.h>
#endif // _WIN32

std::vector<std::string> moUtils::tokenize(const std::string& str, const std::string& delimiters)
{
	std::string client = str;
	std::vector<std::string> result;

	while ( !client.empty() )
	{
		std::string::size_type dPos = client.find_first_of( delimiters );
		if ( dPos == 0 ) {
			client = client.substr(delimiters.length());
			result.push_back("");
		} else {
			std::string::size_type dPos = client.find_first_of(delimiters);
			std::string element = client.substr(0, dPos);
			result.push_back(element);

			if (dPos == std::string::npos)
				return result;
			else
				client = client.substr(dPos+delimiters.length());
		}
	}

	if ( client.empty() )
		result.push_back("");

	return result;
}

double moUtils::time()
{
#ifdef _WIN32
	return ((double)GetTickCount()) / 1000000.;
#else // _WIN32
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((double)tv.tv_sec) + ((double)tv.tv_usec) / 1000000.;
#endif // _WIN32
}

bool moUtils::inList(const std::string &pattern, const std::string &str, const std::string &delimiters) {
	std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	std::string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while ( std::string::npos != pos || std::string::npos != lastPos ) {
        if ( str.substr(lastPos, pos - lastPos) == pattern )
			return true;
        lastPos = str.find_first_not_of(delimiters, pos);
        pos = str.find_first_of(delimiters, lastPos);
    }

	return false;
}

double moUtils::radToDeg(double rad) {
	return rad * (180 / PI);
}

double moUtils::degToRad(double deg) {
	return deg * (PI / 180);
}
