#ifndef MISSION_STATUS_WIDGET_H
#define MISSION_STATUS_WIDGET_H

#include <QMainWindow>

class QTabWidget;
class QStringList;

class MissionStatus: public QMainWindow
{

public:
	MissionStatus(); 
	~MissionStatus(); 
	
	void setupLayout();
	void setupTabs();
	
	void createMenuBar();
	void createStatusBar();
	
	void readCfgs();

private:

	//Menu Bar
	QMenu *	_fileMenu;
	QAction *_createIssueAction;
	QAction* _exportIssuesAction;
	QAction *_exitAppAction;
	
	QTabWidget* _tabWidget;
	
	QStringList _drives;
	QStringList _machines;

};

#endif //MISSION_STATUS_WIDGET_H
