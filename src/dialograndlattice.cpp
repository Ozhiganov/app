/***************************************************************************
 SocNetV: Social Network Visualizer
 version: 2.5
 Written in Qt

                         dialograndlattice.cpp  -  description
                             -------------------
    copyright            : (C) 2005-2018 by Dimitris B. Kalamaras
    email                : dimitris.kalamaras@gmail.com
    website:             : http://dimitris.apeiro.gr
    project site         : http://socnetv.org

 ***************************************************************************/

/*******************************************************************************
*     This program is free software: you can redistribute it and/or modify     *
*     it under the terms of the GNU General Public License as published by     *
*     the Free Software Foundation, either version 3 of the License, or        *
*     (at your option) any later version.                                      *
*                                                                              *
*     This program is distributed in the hope that it will be useful,          *
*     but WITHOUT ANY WARRANTY; without even the implied warranty of           *
*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
*     GNU General Public License for more details.                             *
*                                                                              *
*     You should have received a copy of the GNU General Public License        *
*     along with this program.  If not, see <http://www.gnu.org/licenses/>.    *
********************************************************************************/



#include <QDebug>
#include <QSpinBox>
#include <QRadioButton>
#include <QPushButton>
#include <QDoubleSpinBox>
#include <QGraphicsColorizeEffect>

#include "dialograndlattice.h"


DialogRandLattice::DialogRandLattice(QWidget *parent) : QDialog(parent)
{
    ui.setupUi(this);

    //

    connect ( ui.buttonBox, &QDialogButtonBox::accepted,
              this, &DialogRandLattice::gatherData );


    connect(ui.lengthSpinBox, SIGNAL(valueChanged(int)),
            this, SLOT(lengthChanged(int)));


    ui.buttonBox -> button (QDialogButtonBox::Ok) -> setDefault(true);

}



void DialogRandLattice::lengthChanged(int l) {
    ui.nodesSpinBox->setValue(l*l);
}



void DialogRandLattice::gatherData() {
    qDebug() << "DialogRandSmallWorld::gatherData() " ;
    nodes = ui.nodesSpinBox->value();
    length = ui.lengthSpinBox->value();
    dimension = ui.dimSpinBox->value();
    neighLength = ui.neiSpinBox->value();
    mode = (ui.directedRadioButton->isChecked() ? "digraph" : "graph" );
    diag = (ui.diagCheckBox -> isChecked() ? true : false);
    qDebug() << "nodes " << nodes ;
    qDebug() << "length " << length;
    qDebug() << "dimension " << dimension;
    qDebug() << "neighLength" << neighLength;
    qDebug() << "mode " << mode;
    qDebug() << "diag " << diag;

    emit userChoices(nodes, length, dimension, neighLength, mode, diag);

}

