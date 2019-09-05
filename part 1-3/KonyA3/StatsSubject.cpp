#include "StatsSubject.h"
#include "StatsObserver.h"
StatsSubject::StatsSubject()
{
	_observers = new list<StatsObserver*>;
}
StatsSubject::~StatsSubject()
{
	delete _observers;
}
void StatsSubject::AttachStats(StatsObserver* o) {
	_observers->push_back(o);
}
void StatsSubject::Detach(StatsObserver* o) {
	_observers->remove(o);
}
void StatsSubject::NotifyStats() {
	list<StatsObserver*>::iterator i = _observers->begin();
	for (; i != _observers->end(); ++i)
		(*i)->UpdateStats();
};

