/*
 * $Id: ts_generator.h 5395 2012-03-02 21:19:59Z johnsonb $
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef ts_generator_H
#define ts_generator_H

#include "dds_generator.h"

#include <string>

namespace java_ts_generator {
  void generate(UTL_ScopedName* name);
}

class ts_generator : public dds_generator {
public:
  ts_generator();

  bool gen_const(UTL_ScopedName*, bool, AST_Expression::ExprType,
                 AST_Expression::AST_ExprValue*)
  { return true; }

  bool gen_enum(UTL_ScopedName*,
                const std::vector<AST_EnumVal*>&, const char*)
  { return true; }

  bool gen_struct(UTL_ScopedName* name,
                  const std::vector<AST_Field*>& fields, const char* repoid);

  bool gen_typedef(UTL_ScopedName*, AST_Type*, const char*)
  { return true; }

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

  bool gen_union(UTL_ScopedName*, const std::vector<AST_UnionBranch*>&,
                 AST_Type*, const char*);

private:
  std::string idl_template_, h_template_, cpp_template_;
};

#endif
