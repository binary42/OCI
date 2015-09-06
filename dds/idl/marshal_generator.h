/*
 * $Id: marshal_generator.h 5395 2012-03-02 21:19:59Z johnsonb $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef marshal_generator_H
#define marshal_generator_H

#include "dds_generator.h"

class marshal_generator : public dds_generator {
public:
  bool gen_const(UTL_ScopedName*, bool, AST_Expression::ExprType,
                 AST_Expression::AST_ExprValue*)
  { return true; }

  bool gen_enum(UTL_ScopedName* name,
                const std::vector<AST_EnumVal*>& contents, const char* repoid);

  bool gen_struct(UTL_ScopedName* name,
                  const std::vector<AST_Field*>& fields, const char* repoid);

  bool gen_typedef(UTL_ScopedName* name, AST_Type* base, const char* repoid);

  bool gen_interf(UTL_ScopedName*, bool,
                  const std::vector<AST_Interface*>&,
                  const std::vector<AST_Interface*>&,
                  const std::vector<AST_Attribute*>&,
                  const std::vector<AST_Operation*>&, const char*)
  { return true; }

  bool gen_interf_fwd(UTL_ScopedName*)
  { return true; }

  bool gen_native(UTL_ScopedName*, const char*)
  { return true; }

  bool gen_union(UTL_ScopedName* name,
                 const std::vector<AST_UnionBranch*>& branches,
                 AST_Type* discriminator,
                 const char* repoid);
};

#endif
