/*
 * $Id: v8_generator.h 5920 2013-01-21 22:46:36Z mitza $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef v8_generator_H
#define v8_generator_H

#include "dds_generator.h"

class v8_generator : public dds_generator {

public:
  v8_generator() : first_(true) {}

private:
  bool gen_const(UTL_ScopedName*, bool, AST_Expression::ExprType,
                 AST_Expression::AST_ExprValue*)
  { return true; }

  bool gen_enum(UTL_ScopedName* name,
                const std::vector<AST_EnumVal*>& contents, const char* repoid);

  bool gen_struct(UTL_ScopedName* name,
                  const std::vector<AST_Field*>& fields, const char* repoid);

  bool gen_typedef(UTL_ScopedName* name, AST_Type* type, const char* repoid);

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
                 AST_Type* type, const char* repoid);

  void fwd_decl();

  bool first_;
};

#endif
