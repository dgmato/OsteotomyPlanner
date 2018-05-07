/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

// Qt includes

// VTK includes
#include <vtkSmartPointer.h>

// Planner Logic includes
#include <vtkMRMLThreeDViewDisplayableManagerFactory.h>
#include <vtkSlicerPlannerLogic.h>

// Planner includes
#include "qSlicerPlannerModule.h"
#include "qSlicerPlannerModuleWidget.h"

//-----------------------------------------------------------------------------

#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
#include <QtPlugin>
Q_EXPORT_PLUGIN2(qSlicerPlannerModule, qSlicerPlannerModule);
#endif
//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerPlannerModulePrivate
{
public:
  qSlicerPlannerModulePrivate();
};

//-----------------------------------------------------------------------------
// qSlicerPlannerModulePrivate methods

//-----------------------------------------------------------------------------
qSlicerPlannerModulePrivate::qSlicerPlannerModulePrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerPlannerModule methods

//-----------------------------------------------------------------------------
qSlicerPlannerModule::qSlicerPlannerModule(QObject* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerPlannerModulePrivate)
{
}

//-----------------------------------------------------------------------------
qSlicerPlannerModule::~qSlicerPlannerModule()
{
}

//-----------------------------------------------------------------------------
QString qSlicerPlannerModule::helpText() const
{
  return "This module helps with planning bone surgeries.";
}

//-----------------------------------------------------------------------------
QString qSlicerPlannerModule::acknowledgementText() const
{
  return "TODO";
}

//-----------------------------------------------------------------------------
QStringList qSlicerPlannerModule::contributors() const
{
  QStringList moduleContributors;
  moduleContributors << QString("Johan Andruejol (Kitware Inc.), Sam Horvath (Kitware Inc.)");
  return moduleContributors;
}

//-----------------------------------------------------------------------------
QIcon qSlicerPlannerModule::icon() const
{
  return QIcon(":/Icons/Planner.png");
}

//-----------------------------------------------------------------------------
QStringList qSlicerPlannerModule::categories() const
{
  return QStringList() << "Osteotomy Planning";
}

//-----------------------------------------------------------------------------
QStringList qSlicerPlannerModule::dependencies() const
{
  return QStringList() << "Planes";
}

//-----------------------------------------------------------------------------
void qSlicerPlannerModule::setup()
{
  this->Superclass::setup();
}

//-----------------------------------------------------------------------------
qSlicerAbstractModuleRepresentation* qSlicerPlannerModule
::createWidgetRepresentation()
{
  return new qSlicerPlannerModuleWidget;
}

//-----------------------------------------------------------------------------
vtkMRMLAbstractLogic* qSlicerPlannerModule::createLogic()
{
  return vtkSlicerPlannerLogic::New();
}
