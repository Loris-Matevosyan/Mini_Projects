#ifndef _LOG_
#define _LOG_

#include <opencv2/core/utils/logger.hpp>



inline void voidLog()
{
	cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_SILENT);
}



#endif // _LOG_
