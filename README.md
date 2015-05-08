# xAODJetReclustering - A RootCore Package

## Installing
The last stable analysis base used is **2.1.30**. To install,
```bash
git clone https://github.com/kratsg/xAODJetReclustering.git
rc checkout_pkg atlasoff/Reconstruction/Jet/JetSubStructureUtils/tags/JetSubStructureUtils-00-02-08
rc checkout_pkg atlasoff/Reconstruction/Jet/JetSubStructureMomentTools/tags/JetSubStructureMomentTools-00-01-14
rc find_packages
rc compile
```

## Configurations for `JetReclustering` algorithm

Variable | Type | Default | Description
---------|------|---------|-------------
m_inputJetName | std::string | | name of the input jet container for reclustering
m_outputJetName | std::string | | name of the output jet container holding reclustered jets
m_clusteringAlgorithmName | std::string | antikt_algorithm | how to recluster the input jets
m_outputXAODName | std::string | | if defined, put the reclustered jets in an output xAOD file of the given name
m_radius | float | 1.0 | radius of large-R reclustered jets
m_debug | bool | false | enable verbose debugging information

## Using xAOD Jet Reclustering

### Incorporating in existing code

If you wish to incorporate `JetReclustering` directly into your code, add this package as a dependency in `cmt/Makefile.RootCore` and then a header

```c++
#include <xAODJetReclustering/Helpers.h>
```

to get started. At this point, you can set up your standard tool in the `initialize()` portion of your algorithm as a pointer

```c++
JetRecTool* m_jetReclusteringTool = xAODJetReclustering::JetReclusteringTool(m_inputJetName, m_outputJetName, m_radius, m_clusteringAlgorithm);
```

and then simply call `m_jetReclusteringTool->execute()` in the `execute()` portion of your algorithm to fill the TStore with the appropriate container(s).

### Incorporating in algorithm chain

This is the least destructive option since it requires **no change** to your existing code. All you need to do is create a new `JetReclustering` algorithm and add it to the job before other algorithms downstream that want access to the reclustered jets. It is highly configurable. In your runner macro, add the header

```c++
#include <xAODJetReclustering/JetReclustering.h>
```

and then simply set up your algorithm like so

```c++
// initialize and set it up
JetReclustering* jetReclusterer = new JetReclustering();
jetReclusterer->m_inputJetName = "AntiKt4LCTopoJets";
jetReclusterer->m_outputJetName = "AntiKt10LCTopoJetsRCAntiKt4LCTopoJets";

// ...
// ...
// ...

// add it to your job sometime later
job.algsAdd(jetReclusterer);
```

### Studies and Example Usage

See [kratsg/ReclusteringStudies](https://github.com/kratsg/ReclusteringStudies) for studies and example usage.

#### Authors
- [Giordon Stark](https://github.com/kratsg)
