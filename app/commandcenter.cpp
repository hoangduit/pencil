#include "commandcenter.h"

#include <QMessageBox>
#include <QPushButton>

#include "editor.h"
#include "viewmanager.h"
#include "layermanager.h"
#include "util.h"

#include "layerbitmap.h"
#include "layervector.h"
#include "bitmapimage.h"
#include "vectorimage.h"





CommandCenter::CommandCenter(QObject* parent) : QObject(parent) {}

CommandCenter::~CommandCenter() {}

void CommandCenter::importSound()
{
    Layer* layer = mEditor->layers()->currentLayer();
    Q_ASSERT ( layer )

    if ( layer->type() != Layer::SOUND )
    {
        QMessageBox msg;
        msg.setText( tr( "No sound layer exists as a destination for your import. Create a new sound layer?" ) );
        QAbstractButton* acceptButton = msg.addButton( tr( "Create sound layer" ), QMessageBox::AcceptRole );
        msg.addButton( tr( "Don't create layer" ), QMessageBox::RejectRole );

        msg.exec();
        if ( msg.clickedButton() == acceptButton )
        {
            //SoundLayer();
            layer = mEditor->layers()->currentLayer();
        }
        else
        {
            return;
        }
    }
    /*
    if ( !( ( LayerSound* )layer )->isEmpty() )
    {
    QMessageBox msg;
    msg.setText( "The sound layer you have selected already contains a sound item. Please select another." );
    msg.exec();
    return;
    }

    if ( filePath.isEmpty() || filePath == "fromDialog" )
    {
    QSettings settings( "Pencil", "Pencil" );
    QString initialPath = settings.value( "lastImportPath", QVariant( QDir::homePath() ) ).toString();
    if ( initialPath.isEmpty() ) initialPath = QDir::homePath();
    filePath = QFileDialog::getOpenFileName( mMainWindow, tr( "Import sound..." ), initialPath, tr( "WAV(*.wav);;MP3(*.mp3)" ) );
    if ( !filePath.isEmpty() )
    {
    settings.setValue( "lastImportPath", QVariant( filePath ) );
    }
    else
    {
    return;
    }
    }
    ( ( LayerSound* )layer )->loadSoundAtFrame( filePath, currentFrame() );
    */
    //mTimeLine->updateContent();
}

void CommandCenter::ZoomIn()
{
    Q_ASSERT( mEditor );
    float newScaleValue = mEditor->view()->scaling() * 1.2;
    mEditor->view()->scale( newScaleValue );
}

void CommandCenter::ZoomOut()
{
    Q_ASSERT( mEditor );
    float newScaleValue = mEditor->view()->scaling() * 0.8;
    mEditor->view()->scale( newScaleValue );
}

void CommandCenter::flipX()
{
    auto view = mEditor->view();

    bool b = view->isFlipHorizontal();
    view->flipHorizontal( !b );
}

void CommandCenter::flipY()
{
    auto view = mEditor->view();

    bool b = view->isFlipVertical();
    view->flipVertical( !b );
}

void CommandCenter::GotoNextFrame()
{

}

void CommandCenter::GotoPrevFrame()
{

}

void CommandCenter::GotoNextKeyFrame()
{

}

void CommandCenter::GotoPrevKeyFrame()
{

}

