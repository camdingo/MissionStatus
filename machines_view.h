#ifndef MACHINES_VIEW_H
#define MACHINES_VIEW_H

#include <QWidget>
#include <QStringList>

#include "machine_widget.h"

class MachinesView: public QWidget
{

public:
	MachinesView(QWidget* parent, QStringList const& machines);
	~MachinesView();
	
	void setupLayout();

private:

	QStringList _bases;
	QStringList _wks;
	QStringList _servers;
	QStringList _misc;
	
};

#endif //MACHINES_VIEW_H
