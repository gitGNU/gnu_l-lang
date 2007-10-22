include "include/l/type.l";

// We represent the subtype relationship by two doublehash.
// It really could be modelled in a Prolog or Datalog-like language.
// The main problem is the one of finding if there is a path between two nodes in a DAG;
// But there are also other problems, such as finding a common ancestor between two nodes.
//
// Note: the direct_subtype hash has no use except for debugging for now.
// 
// Note: creation of large type hierarchies could be slow and take a
// lot of memory; however interrogation of the database is immediate.

// Note: Judy has good support for multidimensional arrays; we could
// take advantage of this here if we had a better suited structure
// than the hash.

// The supertype hash: maps a type to its supertypes
global direct_supertype_hash:Hash< Type, Hash< Type, Bool>>;
global supertype_hash:Hash< Type, Hash< Type, Bool>>;

// The subtype hash: maps a type to its subtypes
global direct_subtype_hash:Hash< Type, Hash< Type, Bool>>;
global subtype_hash:Hash< Type, Hash< Type, Bool>>;


// When we have null, this will be null.
constant null_hash_type_bool = cast( Hash< Type, Bool>, 0);

// This is for testing only.
//type Type = Int;

// We need a Type, named Any, that is the subtype of anything.
// Exemple of use: Any * (pointer to anything). null serait une
// valeur de ce type.

// Another example: typealias Exit = Any.


function init__subtype() -> Void =
{
  direct_supertype_hash = cast( Hash< Type, Hash< Type, Bool>>, make_hash_table());
  supertype_hash = cast( Hash< Type, Hash< Type, Bool>>, make_hash_table());

  direct_subtype_hash = cast( Hash< Type, Hash< Type, Bool>>, make_hash_table());
  subtype_hash = cast( Hash< Type, Hash< Type, Bool>>, make_hash_table());
  
};

function define_subtype_relationship( sub:Type, super:Type) -> Void =
{
  let hashsub:Hash<Type, Bool>;
  let hashsup:Hash<Type, Bool>;

  // Fill the direct_supertype Hash.
  if( (hashsub = direct_supertype_hash[sub]) == null_hash_type_bool)
    {
      hashsub = direct_supertype_hash[sub] = cast( Hash<Type, Bool>, make_hash_table());
    };
  hashsub[super] = true;

  // Fill the direct_subtype Hash.
  if( (hashsup = direct_supertype_hash[super]) == null_hash_type_bool)
    {
      hashsup = direct_supertype_hash[super] = cast(Hash<Type, Bool>,make_hash_table());
    };
  hashsup[sub] = true;

  // Fill the supertype and subtype hashes.
  if( (hashsup = supertype_hash[super]) == null_hash_type_bool)
    {
      // super is not yet in database.
      subtype_hash[super] = cast( Hash<Type, Bool>, make_hash_table());
      hashsup = supertype_hash[super] = cast( Hash<Type, Bool>, make_hash_table());

      // Super is a subtype and supertype of itself
      supertype_hash[super][super] = true;
      subtype_hash[super][super] = true;
    };
  if( (hashsub = subtype_hash[sub]) == null_hash_type_bool)
    {
      // sub is not yet in database.
      supertype_hash[sub] = cast( Hash<Type, Bool>, make_hash_table());
      hashsub = subtype_hash[sub] = cast( Hash<Type, Bool>, make_hash_table());

      // Sub is a subtype and supertype of itself
      supertype_hash[sub][sub] = true;
      subtype_hash[sub][sub] = true;
    };

  // XXX: can there be problems with judy if the hash is changed
  // whilst it is traversed?
  foreach( (let subtype, let useless_bool1) in hashsub)
  {
    foreach( (let supertype, let useless_bool2) in hashsup)
      {
	supertype_hash[subtype][supertype] = true;
	subtype_hash[supertype][subtype] = true;
      };
  };
};

function is_direct_subtype( sub:Type, super:Type) -> Bool =
{
  let hashsub:Hash<Type, Bool>;
  
  if( (hashsub = direct_supertype_hash[sub]) == null_hash_type_bool)
    {
      false
    }
  else hashsub[super]
};

function is_subtype( sub:Type, super:Type) -> Bool =
{
  let hashsub:Hash<Type, Bool>;
  
  if( (hashsub = supertype_hash[sub]) == null_hash_type_bool)
    {
      false
    }
  else hashsub[super]
};

// Try to coerce FORM for fitting the type INTO. Returns an expanded form
// with the needed transformation if it worked,
// 
// Every expander code that expect arguments of a special type should
// use this function.
function coerced_form( form:Expanded_Form, into:Type) -> Expanded_Form =
{
  let sub = form.type;
  if(sub == into)
    {
      form
    }
  else if(is_subtype( sub, into))
    {
      expand( //Form( cast( $into.type_form$, $form$)))
	     Compound_Form( 'cast',
			    list( into.type_form,
				  cast( Form, form))))
    }
  // We need a correct type printer for this.
  else cast( Exit, (panic( "Error: cannot coerce form XXX to into type XXX\n");0))
  //", gnu_c:form, " into type XXX ");//, gnu_c:into.type_form, "\n");

	 // XXX: Here we can perform transformation when doing
	 // coercion. However, these transformations "coercion_hash" are not transitive.
};



// To test.
function Type( i:Int) -> Type = cast( Type, i);

function test() -> Bool =
{
  init__subtype();

  define_subtype_relationship( Type( 3), Type( 4));
  define_subtype_relationship( Type( 2), Type( 3));
  
  
  //  is_direct_subtype( Type( 3), Type( 2))
  //  is_direct_subtype( Type( 2), Type( 4))
  is_subtype( Type( 2), Type( 4))
};
