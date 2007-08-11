
// Imagine the following structure is defined in some places of the program.
type Point = struct { x:Int;
                      y:Int; }*;


// Now we need to associates objects of this structure (created elsewhere) to
// a special name.  This can be achieved using Hash Tables:
global name_table:Hash<Point, Symbol>;

// But this will make the program more generic and understandable.
// It defines a name attribute for objects of type Point.
attribute Point p.name = (left( arg): name_table[p] = arg,
			  right: name_table[p]);

function test_point() -> Void =
{
  let p = Point( x:3, y:4);
  p.name = 'pointA';
  print( "Point: x:",p.x, ", y:", p.y, ", name:", p.name, "\n");
  print( "name_table[p]:", name_table[p], "\n");
};

// We choose to reuse a point instead of using inheritance for some
//reason, but to hide this to the user of Point3D.
type Point3D = struct { p_:Point;
                        z:Int; }*;

// Redefines the constructor of Point3D. This allow to write
// let p = Point3D( x:1, y:2, z:3); but for now, only in this order.
macro Point3D (xparam, yparam, zparam) = 
{
  //Also, the form creator( Point3D)( ...) will be prefered over this one. 
  creator( Point3D, p_:creator( Point, xparam, yparam), zparam)
};

// At the end, we should write this:
// attribute Point3D p.x = p.p_.x,
//                  p.y = p.p_.y;
// But this is equivalent to:
attribute Point3D p.x = p.p_.x;
attribute Point3D p.y = p.p_.y;

// Which is equivalent to:
//attribute Point3D p.x = (left( arg): p.p_.x = arg, right: p.p_.x);

function test_point3d () -> Point3D =
{
  let p = Point3D( x:1,y:2,z:3);
  print( "Value: ", p.p_.x + p.p_.y + p.z, "\n");
  print( "P.x:", p.x, ", p.y:", p.y, ", p.z:", p.z, "\n");
  p.x = 3;
  p.y = 4;
  p.z = 5;
  print( "P.x:", p.x, ", p.y:", p.y, ", p.z:", p.z, "\n");
  p
};

// You can do this to any type:
type Duration = Int;

// By specifying only left: or right: you can have read-only or
// write-only attributes. Here, a Duration is immutable.
attribute Duration d.second = right:cast( Int, d);
attribute Duration d.minute = (right:cast( Int, cast( Int, d)/60));
attribute Duration d.hour = right:cast( Int, cast( Int, d)/3600);


function test_Duration() -> Void = 
{
  let d = Duration( 8000);
  print( "Duration: ", d.second, " seconds (i.e. ",
	 d.minute, " minutes i.e. ",
	 d.hour,  " hours)\n" );
  //d.seconds = 25;
};


// You can do that on Lists too:
attribute List( Int) l.sum = { let _sum = 0;
			       foreach( let _element in l) {_sum = _sum + _element;}
			       _sum};
			       
function test_list() -> Void = 
{
  let l = list( 1,2,3);
  print( "Sum: ", l.sum, "\n");
};

function test() -> Void = 
{
  name_table = Hash( Point, Symbol);
  test_point();
  test_point3d();
  test_Duration();
  test_list();
};


