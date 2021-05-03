#pragma once

#include <iostream>

// Qt
#include <QMainWindow>

// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>

// Visualization Toolkit (VTK)
#include <vtkRenderWindow.h>

typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;
//This file is the header for the class PCLViewer; we include QMainWindow because this class contains UI elements, we include the PCL headers we will be using and the VTK header for the qvtkWidget. We also define typedefs of the point types and point clouds, this improves readabily.

namespace Ui
{
  class PCLViewer;
}
//We declare the namespace Ui and the class PCLViewer inside it.

class PCLViewer : public QMainWindow
{
  Q_OBJECT
//This is the definition of the PCLViewer class; the macro Q_OBJECT tells the compiler that this object contains UI elements; this imply that this file will be processed through the Meta-Object Compiler (moc).

public:
  explicit PCLViewer (QWidget *parent = 0);
  ~PCLViewer ();
//The constructor and destructor of the PCLViewer class.

public Q_SLOTS:
  void
  randomButtonPressed ();

  void
  RGBsliderReleased ();

  void
  pSliderValueChanged (int value);

  void
  redSliderValueChanged (int value);

  void
  greenSliderValueChanged (int value);

  void
  blueSliderValueChanged (int value);
//These are the public slots; these functions will be linked with UI elements actions.

protected:
  pcl::visualization::PCLVisualizer::Ptr viewer;
  PointCloudT::Ptr cloud;

  unsigned int red;
  unsigned int green;
  unsigned int blue;
};
