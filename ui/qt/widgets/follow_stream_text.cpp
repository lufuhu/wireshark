/* follow_stream_text.cpp
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <ui/qt/widgets/follow_stream_text.h>

#include <main_application.h>

#include <QMouseEvent>
#include <QTextCursor>

// To do:
// - Draw text by hand similar to ByteViewText. This would let us add
//   extra information, e.g. a timestamp column and get rid of
//   max_document_length_ in FollowStreamDialog.

FollowStreamText::FollowStreamText(QWidget *parent) :
    QPlainTextEdit(parent)
{
    setMouseTracking(true);
//    setMaximumBlockCount(1);
    QTextDocument *text_doc = document();
    text_doc->setDefaultFont(mainApp->monospaceFont());
}

void FollowStreamText::mouseMoveEvent(QMouseEvent *event)
{
    emit mouseMovedToTextCursorPosition(cursorForPosition(event->pos()).position());
    QPlainTextEdit::mouseMoveEvent(event);
}

void FollowStreamText::mousePressEvent(QMouseEvent *event)
{
    emit mouseClickedOnTextCursorPosition(cursorForPosition(event->pos()).position());
    QPlainTextEdit::mousePressEvent(event);
}

void FollowStreamText::leaveEvent(QEvent *event)
{
    emit mouseMovedToTextCursorPosition(-1);
    QPlainTextEdit::leaveEvent(event);
}
