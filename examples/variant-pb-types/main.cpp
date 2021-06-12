/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
**
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of a Qt Solutions component.
**
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
****************************************************************************/

#include <QApplication>
#include <QScrollArea>
#include <QGridLayout>
#include <QLabel>
#include <QIcon>
#include <QMap>
#include "qtpropertymanager.h"
#include "qteditorfactory.h"
#include "qttreepropertybrowser.h"
#include "qtbuttonpropertybrowser.h"
#include "qtgroupboxpropertybrowser.h"
#include "qtvariantproperty.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    auto* w = new QWidget();
    auto* groupManager = new QtGroupPropertyManager(w);
    auto* group = groupManager->addProperty("QObject");

    auto* vpm = new QtVariantPropertyManager(w);
    group->addSubProperty(vpm->addProperty(QMetaType::QString, "objectName"));
    group->addSubProperty(vpm->addProperty(QMetaType::Bool, "enabled"));
    group->addSubProperty(vpm->addProperty(QMetaType::QRect, "geometry"));
    group->addSubProperty(vpm->addProperty(QMetaType::QSizePolicy, "sizePolicy"));
    group->addSubProperty(vpm->addProperty(QMetaType::QSize, "sizeIncrement"));
    group->addSubProperty(vpm->addProperty(QMetaType::Bool, "mouseTracking"));

    auto* enumProperty = vpm->addProperty(QtVariantPropertyManager::enumTypeId(), "direction");
    auto types = QStringList() << "Up" << "Right" << "Down" << "Left";
    enumProperty->setAttribute("enumNames", types);
    enumProperty->setValue(0);
    group->addSubProperty(enumProperty);

    auto* valueProperty = vpm->addProperty(QMetaType::Int, "value");
    valueProperty->setAttribute("minimum", 0);
    valueProperty->setAttribute("maximum", 100);
    group->addSubProperty(valueProperty);

    auto* browser = new QtTreePropertyBrowser(w);
    auto* variantEditorFactory = new QtVariantEditorFactory(w);
    browser->setFactoryForManager(vpm, variantEditorFactory);
    browser->addProperty(group);

    QGridLayout *layout = new QGridLayout(w);
    QLabel *lable = new QLabel("Editable Tree Property Browser");
    lable->setWordWrap(true);
    lable->setFrameShadow(QFrame::Sunken);
    lable->setFrameShape(QFrame::Panel);
    lable->setAlignment(Qt::AlignCenter);

    layout->addWidget(lable, 0, 0);
    layout->addWidget(browser, 1, 0);
    w->show();

    int ret = app.exec();
    delete w;
    return ret;
}
