#ifndef MACHINE_WIDGET_H
#define MACHINE_WIDGET_H

#include <QWidget>

//#include "machine_detailed_dialog.h"

class MachineWidget: public QWidget
{

	static const QString RED_BACKGROUND;
	static const QString YELLOW_BACKGROUND;
	static const QString GREEN_BACKGROUND;

public:
	MachineWidget(QWidget* parent, QString name);
	~MachineWidget();
	
	void setupLayout();
	void createConnections();

private:
	QString _machineName;
//	MachineDetailedDialog* _machineDD;
	
};

#endif //MACHINE_WIDGET_H
