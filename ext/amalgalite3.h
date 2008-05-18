#ifndef __AMALGALITE_H__
#define __AMALGALITE_H__

#include "ruby.h"
#include "sqlite3.h"

/** module and classes **/
extern VALUE mA;
extern VALUE mAS;
extern VALUE mASV;
extern VALUE cAS_Database;
extern VALUE cAS_Statement;
extern VALUE eAS_Error;

/* wrapper struct around the sqlite3 opaque pointer */
typedef struct am_sqlite3 {
  sqlite3 *db;
} am_sqlite3;

/* wrapper struct around the sqlite3_statement opaque pointer */
typedef struct am_sqlite3_stmt {
  sqlite3_stmt *stmt;
  VALUE         remaining_sql;
} am_sqlite3_stmt;

/***********************************************************************
 * Prototypes
 **********************************************************************/

/*----------------------------------------------------------------------
 * Database functions
 *---------------------------------------------------------------------*/
extern void  am_define_constants_under(VALUE);
extern VALUE am_sqlite3_database_alloc(VALUE klass);
extern void  am_sqlite3_database_free(am_sqlite3*);
extern VALUE am_sqlite3_database_open(int argc, VALUE* argv, VALUE self);
extern VALUE am_sqlite3_database_close(VALUE self);
extern VALUE am_sqlite3_database_open16(VALUE self, VALUE rFilename);
extern VALUE am_sqlite3_database_last_insert_rowid(VALUE self);
extern VALUE am_sqlite3_database_is_autocommit(VALUE self);

extern VALUE am_sqlite3_database_prepare(VALUE self, VALUE rSQL);

/*----------------------------------------------------------------------
 * Statement functions
 *---------------------------------------------------------------------*/
extern VALUE am_sqlite3_statement_alloc(VALUE klass);
extern void  am_sqlite3_statement_free(am_sqlite3_stmt* );
extern VALUE am_sqlite3_statement_sql(VALUE self);
extern VALUE am_sqlite3_statement_close(VALUE self);
extern VALUE am_sqlite3_statement_step(VALUE self);
extern VALUE am_sqlite3_statement_column_count(VALUE self);
extern VALUE am_sqlite3_statement_column_name(VALUE self, VALUE index);
extern VALUE am_sqlite3_statement_column_value(VALUE self, VALUE index);
extern VALUE am_sqlite3_statement_reset(VALUE self);
extern VALUE am_sqlite3_statement_clear_bindings(VALUE self);
extern VALUE am_sqlite3_statement_bind_parameter_count(VALUE self);
extern VALUE am_sqlite3_statement_bind_parameter_index(VALUE self, VALUE parameter_name);
extern VALUE am_sqlite3_statement_remaining_sql(VALUE self);
extern VALUE am_sqlite3_statement_bind_text(VALUE self, VALUE position, VALUE value);
extern VALUE am_sqlite3_statement_bind_int(VALUE self, VALUE position, VALUE value);
extern VALUE am_sqlite3_statement_bind_int64(VALUE self, VALUE position, VALUE value);
extern VALUE am_sqlite3_statement_bind_double(VALUE self, VALUE position, VALUE value);
extern VALUE am_sqlite3_statement_bind_null(VALUE self, VALUE position);

/***********************************************************************
 * Helpful macros
 **********************************************************************/

#define SQLINT64_2NUM(x)      ( LL2NUM( x ) )
#define SQLUINT64_2NUM(x)     ( ULL2NUM( x ) )
#define NUM2SQLINT64( obj )   ( NUM2LL( obj ) )
#define NUM2SQLUINT64( obj )  ( NUM2ULL( obj ) )
#endif