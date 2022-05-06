#ifndef DRIVES_VIEW_H
#define DRIVES_VIEW_H

#include <QWidget>
#include <QStringList>

class DrivesView: public QWidget
{

public:
	DrivesView(QWidget* parent, QStringList const& drives);
	~DrivesView();
	
	void setupLayout();

private:
	QStringList _drives;
	
};

#endif //DRIVES_VIEW_H
