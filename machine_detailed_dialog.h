#ifndef MACHINE_DETAILED_DIALOG_H
#define MACHINE_DETAILED_DIALOG_H

#include <QDialog>

#include "widgets/cpuwidget.h"
#include "widgets/ramwidget.h"

class MachineDetailedDialog: public QDialog
{
	Q_OBJECT

public:
	MachineDetailedDialog(QWidget* parent);
	~MachineDetailedDialog();
	
	void setupLayout();
	
public slots:
	void openDialog();

private:
	CpuWidget* _cpu;
	RamWidget* _ram;
	//GpuWidget* _gpu;
};

#endif //MACHINE_DETAILED_DIALOG_H
