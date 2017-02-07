#include "utility/utilityPathDetection.h"

#include <QSysInfo>

#include "utility/path_detector/java_runtime/JavaPathDetectorLinux.h"
#include "utility/path_detector/java_runtime/JavaPathDetectorMac.h"
#include "utility/path_detector/java_runtime/JavaPathDetectorWindows.h"

#include "utility/path_detector/cxx_header/CxxFrameworkPathDetector.h"
#include "utility/path_detector/cxx_header/CxxHeaderPathDetector.h"
#include "utility/path_detector/cxx_header/CxxVsHeaderPathDetector.h"

std::shared_ptr<CombinedPathDetector> utility::getJavaRuntimePathDetector()
{
	std::shared_ptr<CombinedPathDetector> combinedDetector = std::make_shared<CombinedPathDetector>();
	if (QSysInfo::windowsVersion() != QSysInfo::WV_None)
	{
		combinedDetector->addDetector(std::make_shared<JavaPathDetectorWindows>("1.8"));
	}
	else if (QSysInfo::macVersion() != QSysInfo::MV_None)
	{
		combinedDetector->addDetector(std::make_shared<JavaPathDetectorMac>("1.8"));
	}
	else
	{
		combinedDetector->addDetector(std::make_shared<JavaPathDetectorLinux>("1.8"));
	}

	return combinedDetector;
}

std::shared_ptr<CombinedPathDetector> utility::getCxxVsHeaderPathDetector()
{
	std::shared_ptr<CombinedPathDetector> combinedDetector = std::make_shared<CombinedPathDetector>();
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(14, false, APPLICATION_ARCHITECTURE_X86_32));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(14, false, APPLICATION_ARCHITECTURE_X86_64));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(14, true, APPLICATION_ARCHITECTURE_X86_32));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(14, true, APPLICATION_ARCHITECTURE_X86_64));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(12, false, APPLICATION_ARCHITECTURE_X86_32));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(12, false, APPLICATION_ARCHITECTURE_X86_64));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(12, true, APPLICATION_ARCHITECTURE_X86_32));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(12, true, APPLICATION_ARCHITECTURE_X86_64));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(11, false, APPLICATION_ARCHITECTURE_X86_32));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(11, false, APPLICATION_ARCHITECTURE_X86_64));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(11, true, APPLICATION_ARCHITECTURE_X86_32));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(11, true, APPLICATION_ARCHITECTURE_X86_64));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(9, false, APPLICATION_ARCHITECTURE_X86_32));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(9, false, APPLICATION_ARCHITECTURE_X86_64));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(9, true, APPLICATION_ARCHITECTURE_X86_32));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(9, true, APPLICATION_ARCHITECTURE_X86_64));
	return combinedDetector;
}

std::shared_ptr<CombinedPathDetector> utility::getCxxHeaderPathDetector()
{
	std::shared_ptr<CombinedPathDetector> combinedDetector = std::make_shared<CombinedPathDetector>();
	combinedDetector->addDetector(std::make_shared<CxxHeaderPathDetector>("gcc"));
	combinedDetector->addDetector(std::make_shared<CxxHeaderPathDetector>("clang"));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(14, false, APPLICATION_ARCHITECTURE_X86_32));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(14, false, APPLICATION_ARCHITECTURE_X86_64));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(14, true, APPLICATION_ARCHITECTURE_X86_32));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(14, true, APPLICATION_ARCHITECTURE_X86_64));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(12, false, APPLICATION_ARCHITECTURE_X86_32));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(12, false, APPLICATION_ARCHITECTURE_X86_64));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(12, true, APPLICATION_ARCHITECTURE_X86_32));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(12, true, APPLICATION_ARCHITECTURE_X86_64));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(11, false, APPLICATION_ARCHITECTURE_X86_32));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(11, false, APPLICATION_ARCHITECTURE_X86_64));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(11, true, APPLICATION_ARCHITECTURE_X86_32));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(11, true, APPLICATION_ARCHITECTURE_X86_64));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(9, false, APPLICATION_ARCHITECTURE_X86_32));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(9, false, APPLICATION_ARCHITECTURE_X86_64));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(9, true, APPLICATION_ARCHITECTURE_X86_32));
	combinedDetector->addDetector(std::make_shared<CxxVsHeaderPathDetector>(9, true, APPLICATION_ARCHITECTURE_X86_64));
	return combinedDetector;
}

std::shared_ptr<CombinedPathDetector> utility::getCxxFrameworkPathDetector()
{
	std::shared_ptr<CombinedPathDetector> combinedDetector = std::make_shared<CombinedPathDetector>();
	combinedDetector->addDetector(std::make_shared<CxxFrameworkPathDetector>("gcc"));
	combinedDetector->addDetector(std::make_shared<CxxFrameworkPathDetector>("clang"));
	return combinedDetector;
}
