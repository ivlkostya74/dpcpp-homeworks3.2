#include <iostream>
#include "Observer.h"

int main()
{
	Observed obsed;
	ObserverOnWarning oow1;
	ObserverOnWarning oow2;
	ObserverOnError ooe1("ObserverOnError.txt");
	ObserverOnError ooe2("ObserverOnError.txt");
	ObserverOnFatalError oofe1("ObserverOnFatalError.txt");
	ObserverOnFatalError oofe2("ObserverOnFatalError.txt");

	obsed.addObserver(&oow1).addObserver(&oow2)
		.addObserver(&ooe1).addObserver(&ooe2)
		.addObserver(&oofe1).addObserver(&oofe2);

	obsed.warning("Something not good");
	obsed.error("Something bad");
	obsed.fatalError("Something very bad");

	obsed.removeObserver(&oow1)
		.removeObserver(&ooe1)
		.removeObserver(&oofe1);

	return 0;
}