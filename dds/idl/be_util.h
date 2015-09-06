/* -*- c++ -*- */

//=============================================================================
/**
 *  @file    be_util.h
 *
 *  $Id: be_util.h 3520 2010-07-28 20:22:08Z mitza $
 *
 *  Static helper methods used by multiple visitors.
 *
 *
 *  @author Gary Maxey
 *  @author Jeff Parsons
 */
//=============================================================================

#ifndef OPENDDS_IDL_BE_UTIL_H
#define OPENDDS_IDL_BE_UTIL_H

class TAO_OutStream;
class be_module;
class AST_Decl;
class AST_Generator;

class be_util
{
public:
  /// Special BE arg call factored out of DRV_args.
  static void
  prep_be_arg (char *s);

  /// Checks made after parsing args.
  static void
  arg_post_proc (void);

  /// Display usage of BE-specific options.
  static void
  usage (void);

  /// Create an AST node generator.
  static AST_Generator *
  generator_init (void);
};

#endif // if !defined

