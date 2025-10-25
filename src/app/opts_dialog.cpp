
/*
    SPDX-FileCopyrightText: 2025 Igor Mironchik <igor.mironchik@gmail.com>
    SPDX-License-Identifier: GPL-3.0-or-later
*/

// Qt include.
#include <QCheckBox>

// LicenseChange include.
#include "opts_dialog.h"
#include "ui_opts_dialog.h"

//
// OptsDialogPrivate
//

class OptsDialogPrivate
{
public:
    explicit OptsDialogPrivate(OptsDialog *parent)
        : q(parent)
    {
    }

    //! Init.
    void init();

    //! UI.
    Ui::OptsDialog m_ui;
    //! Parent.
    OptsDialog *q;
}; // class OptsDialogPrivate;

void OptsDialogPrivate::init()
{
    m_ui.setupUi(q);
}

//
// OptsDialog
//

OptsDialog::OptsDialog(QWidget *parent)
    : QDialog(parent)
    , d(new OptsDialogPrivate(this))
{
    d->init();
}

OptsDialog::~OptsDialog()
{
}

bool OptsDialog::onlyOneLicense() const
{
    return d->m_ui.m_one->isChecked();
}

bool OptsDialog::isCaseSensitive() const
{
    return d->m_ui.m_case->isChecked();
}
