#ifndef MACHINE_WIDGET_H
#define MACHINE_WIDGET_H

#include <QWidget>

#include "widgets/cpuwidget.h"
#include "widgets/ramwidget.h"

class MachineWidget: public QWidget
{

public:
	MachineWidget(QWidget* parent, QString name);
	~MachineWidget();
	
	void setupLayout();

private:
	QString _machineName;

	CpuWidget* _cpu;
	RamWidget* _ram;
};

#endif //MACHINE_WIDGET_H
