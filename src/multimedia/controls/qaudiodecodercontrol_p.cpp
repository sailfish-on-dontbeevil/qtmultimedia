/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qmediacontrol_p.h"
#include "qaudiodecodercontrol_p.h"

QT_BEGIN_NAMESPACE


/*!
    \class QAudioDecoderControl
    \inmodule QtMultimedia

    \ingroup multimedia
    \ingroup multimedia_control

    \brief The QAudioDecoderControl class provides access to the audio decoding
    functionality of a QMediaService.

    \preliminary

    The functionality provided by this control is exposed to application
    code through the QAudioDecoder class.

    The interface name of QAudioDecoderControl is \c com.nokia.Qt.QAudioDecoderControl/1.0 as
    defined in QAudioDecoderControl_iid.

    \sa QMediaService::requestControl(), QAudioDecoder
*/

/*!
    \macro QAudioDecoderControl_iid

    \c com.nokia.Qt.QAudioDecoderControl/1.0

    Defines the interface name of the QAudioDecoderControl class.

    \relates QAudioDecoderControl
*/

/*!
    Destroys an audio decoder control.
*/
QAudioDecoderControl::~QAudioDecoderControl()
{
}

/*!
    Constructs a new audio decoder control with the given \a parent.
*/
QAudioDecoderControl::QAudioDecoderControl(QObject *parent):
    QMediaControl(*new QMediaControlPrivate, parent)
{
}

/*!
    \fn QAudioDecoderControl::state() const

    Returns the state of a player control.
*/

/*!
    \fn QAudioDecoderControl::stateChanged(QAudioDecoder::State state)

    Signals that the \a state of a player control has changed.

    \sa state()
*/

/*!
    \fn QAudioDecoderControl::sourceFilename() const

    Returns the current media source filename, or a null QString if none (or a device)
*/

/*!
    \fn QAudioDecoderControl::setSourceFilename(const QString &fileName)

    Sets the current source to \a fileName.  Changing the source will
    stop any current decoding and discard any buffers.

    Sources are exclusive, so only one can be set.
*/

/*!
    \fn QAudioDecoderControl::sourceDevice() const

    Returns the current media source QIODevice, or 0 if none (or a file).
*/

/*!
    \fn QAudioDecoderControl::setSourceDevice(QIODevice *device)

    Sets the current source to \a device.  Changing the source will
    stop any current decoding and discard any buffers.

    Sources are exclusive, so only one can be set.
*/

/*!
    \fn QAudioDecoderControl::start()

    Starts decoding the current media.

    If successful the player control will immediately enter the \l {QAudioDecoder::DecodingState}
    {decoding} state.

    \sa state(), read()
*/

/*!
    \fn QAudioDecoderControl::stop()

    Stops playback of the current media and discards any buffers.

    If successful the player control will immediately enter the \l {QAudioDecoder::StoppedState}
    {stopped} state.
*/

/*!
    \fn QAudioDecoderControl::error(int error, const QString &errorString)

    Signals that an \a error has occurred.  The \a errorString provides a more detailed explanation.
*/

/*!
    \fn QAudioDecoderControl::bufferAvailableChanged(bool available)

    Signals that the bufferAvailable property has changed to \a available.
*/

/*!
    \fn QAudioDecoderControl::bufferReady()

    Signals that a new buffer is ready for reading.
*/

/*!
    \fn QAudioDecoderControl::formatChanged(const QAudioFormat &format)

    Signals that the current audio format of the decoder has changed to \a format.

    \sa audioFormat(), setAudioFormat
*/



/*!
    \fn QAudioDecoderControl::audioFormat()
    Returns the current audio format of the decoded stream.

    Any buffers returned should have this format.

    \sa setAudioFormat, audioFormatChanged
*/

/*!
    \fn QAudioDecoderControl::setAudioFormat(const QAudioFormat &format)
    Set the desired audio format for decoded samples to \a format.

    If the decoder does not support this format, \l error() will
    be set to \c FormatError.

    If you do not specify a format, the format of the decoded
    audio itself will be used.  Otherwise, some format conversion
    will be applied.

    If you wish to reset the decoded format to that of the original
    audio file, you can specify an invalid \a format.
*/

#include "moc_qaudiodecodercontrol_p.cpp"
QT_END_NAMESPACE
