/***************************************************************************
                         qgslayoutpdfexportoptionsdialog.h
                         -------------------------------------
    begin                : August 2019
    copyright            : (C) 2019 by Nyall Dawson
    email                : nyall dot dawson at gmail dot com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSLAYOUTPDFEXPORTOPTIONSDIALOG_H
#define QGSLAYOUTPDFEXPORTOPTIONSDIALOG_H

// We don't want to expose this in the public API
#define SIP_NO_FILE

#include <QDialog>
#include "qgis_gui.h"
#include "qgis.h"
#include "ui_qgspdfexportoptions.h"

class QgsGeospatialPdfLayerTreeModel;
class QgsGeospatialPdfLayerFilteredTreeModel;

/**
 * \ingroup gui
 * \brief A dialog for customizing the properties of an exported PDF file from a layout.
 *
 * \note This class is not a part of public API
 * \since QGIS 3.12
 */
class GUI_EXPORT QgsLayoutPdfExportOptionsDialog : public QDialog, private Ui::QgsPdfExportOptionsDialog
{
    Q_OBJECT

  public:
    /**
     * Constructor for QgsLayoutPdfExportOptionsDialog
     * \param parent parent widget
     * \param allowGeospatialPdfExport set to FALSE if geospatial PDF export is blocked
     * \param geospatialPdfReason set to a descriptive translated string explaining why geospatial PDF export is not available if applicable
     * \param geospatialPdfLayerOrder optional layer ID order list for layers in the geospatial PDF file. Any layers not present in this list
     * will instead be appended to the end of the geospatial PDF layer list
     * \param flags window flags
     */
    QgsLayoutPdfExportOptionsDialog( QWidget *parent = nullptr, bool allowGeospatialPdfExport = true, const QString &geospatialPdfReason = QString(), const QStringList &geospatialPdfLayerOrder = QStringList(), Qt::WindowFlags flags = Qt::WindowFlags() );

    //! Sets the text render format
    void setTextRenderFormat( Qgis::TextRenderFormat format );
    //! Returns the current text render format
    Qgis::TextRenderFormat textRenderFormat() const;
    //! Set whether to force vector output
    void setForceVector( bool force );
    //! Returns whether vector output is being forced
    bool forceVector() const;
    //! Sets whether to enable georeferencing options
    void enableGeoreferencingOptions( bool enabled );
    //! Sets whether to enable georeferencing
    void setGeoreferencingEnabled( bool enabled );
    //! Returns whether georeferencing is enabled
    bool georeferencingEnabled() const;
    //! Sets whether to enable metadata
    void setMetadataEnabled( bool enabled );
    //! Returns whether metadata is enabled
    bool metadataEnabled() const;
    //! Sets whether to disable raster tiling
    void setRasterTilingDisabled( bool disabled );
    //! Returns whether raster tiling is disabled
    bool rasterTilingDisabled() const;
    //! Sets whether to simplify geometries
    void setGeometriesSimplified( bool enabled );
    //! Returns whether geometry simplification is enabled
    bool geometriesSimplified() const;

    //! Sets whether to use lossless image compression
    void setLosslessImageExport( bool enabled );
    //! Returns whether lossless image compression is enabled
    bool losslessImageExport() const;

    //! Sets whether to export a Geospatial PDF
    void setExportGeospatialPdf( bool enabled );
    //! Returns whether Geospatial PDF export is enabled
    bool exportGeospatialPdf() const;

    //! Sets the list of export themes
    void setExportThemes( const QStringList &themes );
    //! Returns the list of export themes
    QStringList exportThemes() const;

    //! Returns a list of map layer IDs in the desired order they should appear in a generated Geospatial PDF file
    QStringList geospatialPdfLayerOrder() const;

    //! Returns a list of groups in the desired order they should appear in a generated Geospatial PDF file
    QStringList geospatialPdfGroupOrder() const;

    //! Sets whether to open the pdf after exporting it
    void setOpenAfterExporting( bool enabled );
    //! Returns whether the pdf should be opened after exporting it
    bool openAfterExporting() const;

  private slots:

    void showHelp();
    void showContextMenuForGeospatialPdfStructure( QPoint point, const QModelIndex &index );

  private:
    bool mGeospatialPdfAvailable = true;
    QgsGeospatialPdfLayerTreeModel *mGeospatialPdfStructureModel = nullptr;
    QgsGeospatialPdfLayerFilteredTreeModel *mGeospatialPdfStructureProxyModel = nullptr;
    QMenu *mGeospatialPdfStructureTreeMenu = nullptr;
};

#endif // QGSLAYOUTPDFEXPORTOPTIONSDIALOG_H
