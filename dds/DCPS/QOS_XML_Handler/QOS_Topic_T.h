/**
 * @author Marcel Smit (msmit@remedy.nl)
 *
 * $Id: QOS_Topic_T.h 5638 2012-06-03 18:39:36Z johnnyw $
 *
 * Starting point for parsing the Topic QOS settings.
 *
 */
#ifndef QOS_TOPIC_T_H_
#define QOS_TOPIC_T_H_

#include "QOS_DwDrTp_Base_T.h"

template <typename XML_QOS_TYPE, typename DDS_QOS_TYPE>
class QOS_Topic_T
  : public QOS_DwDrTp_Base_T<XML_QOS_TYPE, DDS_QOS_TYPE>
{
public:
  QOS_Topic_T (void);
  ~QOS_Topic_T (void);

  void read_qos (DDS_QOS_TYPE&, const XML_QOS_TYPE);

private:
  typedef QOS_DwDrTp_Base_T<XML_QOS_TYPE, DDS_QOS_TYPE> DwDrTpBase;
};

#include "dds/DCPS/QOS_XML_Handler/QOS_Topic_T.cpp"

#endif /* QOS_TOPIC_T_H_ */
