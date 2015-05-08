#ifndef xAODJetReclustering_JetxAODJetReclustering_H
#define xAODJetReclustering_JetxAODJetReclustering_H

#include <EventLoop/Algorithm.h>

#include <xAODRootAccess/Init.h>
#include <xAODRootAccess/TEvent.h>
#include <xAODRootAccess/TStore.h>

// jet definition
#include <fastjet/JetDefinition.hh>

// jet reclustering
#include "JetRec/JetRecTool.h"

class JetxAODJetReclustering : public EL::Algorithm
{
public:
  std::string m_inputJetName,
              m_outputJetName,
              m_clusteringAlgorithmName,
              m_outputXAODName;
  float m_radius = 1.0;
  bool m_debug = false;

private:
  /* For counting and statistics */
  xAOD::TEvent *m_event; //!
  xAOD::TStore *m_store; //!

  fastjet::JetAlgorithm m_clusteringAlgorithm; //!
  JetRecTool* m_jetxAODJetReclusteringTool; //!

public:
  // this is a standard constructor
  JetxAODJetReclustering ();

  // these are the functions inherited from Algorithm
  virtual EL::StatusCode setupJob (EL::Job& job);
  virtual EL::StatusCode fileExecute ();
  virtual EL::StatusCode histInitialize ();
  virtual EL::StatusCode changeInput (bool firstFile);
  virtual EL::StatusCode initialize ();
  virtual EL::StatusCode execute ();
  virtual EL::StatusCode postExecute ();
  virtual EL::StatusCode finalize ();
  virtual EL::StatusCode histFinalize ();

  // this is needed to distribute the algorithm to the workers
  ClassDef(JetxAODJetReclustering, 1);
};

#endif