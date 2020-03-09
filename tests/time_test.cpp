#include <boost/test/unit_test.hpp>
#include <boost/version.hpp>
#include <fc/time.hpp>
#include <iostream>

using namespace fc;

BOOST_AUTO_TEST_SUITE(fc)

BOOST_AUTO_TEST_CASE(time_point_sec_test)
{
    time_point_sec tp0(0);
    BOOST_CHECK_EQUAL( "1970-01-01T00:00:00", tp0.to_iso_string() );
    BOOST_CHECK_EQUAL( "19700101T000000", tp0.to_non_delimited_iso_string() );

    time_point_sec tp1(1);
    BOOST_CHECK_EQUAL( "1970-01-01T00:00:01", tp1.to_iso_string() );
    BOOST_CHECK_EQUAL( "19700101T000001", tp1.to_non_delimited_iso_string() );

    time_point_sec tp256(0x100);
    BOOST_CHECK_EQUAL( "1970-01-01T00:04:16", tp256.to_iso_string() );
    BOOST_CHECK_EQUAL( "19700101T000416", tp256.to_non_delimited_iso_string() );

    time_point_sec tp64k(0x10000);
    BOOST_CHECK_EQUAL( "1970-01-01T18:12:16", tp64k.to_iso_string() );
    BOOST_CHECK_EQUAL( "19700101T181216", tp64k.to_non_delimited_iso_string() );

    time_point_sec tp16m(0x1000000);
    BOOST_CHECK_EQUAL( "1970-07-14T04:20:16", tp16m.to_iso_string() );
    BOOST_CHECK_EQUAL( "19700714T042016", tp16m.to_non_delimited_iso_string() );

    time_point_sec tp2gm1(0x7fffffffU);
    BOOST_CHECK_EQUAL( "2038-01-19T03:14:07", tp2gm1.to_iso_string() );
    BOOST_CHECK_EQUAL( "20380119T031407", tp2gm1.to_non_delimited_iso_string() );

    time_point_sec tp2g(0x80000000U);
    BOOST_CHECK_EQUAL( "2038-01-19T03:14:08", tp2g.to_iso_string() );
    BOOST_CHECK_EQUAL( "20380119T031408", tp2g.to_non_delimited_iso_string() );

    time_point_sec tp3g(0xc0000000U);
    if (BOOST_VERSION >= BOOST_VERSION_NUMBER(1,64,0)) {
        BOOST_CHECK_EQUAL( "2072-01-28T16:51:12", tp3g.to_iso_string() );
        BOOST_CHECK_EQUAL( "20720128T165112", tp3g.to_non_delimited_iso_string() );
    }

    BOOST_CHECK( tp0 == time_point_sec() );
    BOOST_CHECK( tp0 < tp1 );
    BOOST_CHECK( tp0 < tp256 );
    BOOST_CHECK( tp0 < tp64k );
    BOOST_CHECK( tp0 < tp16m );
    BOOST_CHECK( tp0 < tp2gm1 );
    BOOST_CHECK( tp0 < tp2g );
    BOOST_CHECK( tp0 < tp3g );
    BOOST_CHECK( tp1 > tp0 );
    BOOST_CHECK( tp1 < tp256 );
    BOOST_CHECK( tp1 < tp64k );
    BOOST_CHECK( tp1 < tp16m );
    BOOST_CHECK( tp1 < tp2gm1 );
    BOOST_CHECK( tp1 < tp2g );
    BOOST_CHECK( tp1 < tp3g );
    BOOST_CHECK( tp256 > tp0 );
    BOOST_CHECK( tp256 > tp1 );
    BOOST_CHECK( tp256 < tp64k );
    BOOST_CHECK( tp256 < tp16m );
    BOOST_CHECK( tp256 < tp2gm1 );
    BOOST_CHECK( tp256 < tp2g );
    BOOST_CHECK( tp256 < tp3g );
    BOOST_CHECK( tp64k > tp0 );
    BOOST_CHECK( tp64k > tp1 );
    BOOST_CHECK( tp64k > tp256 );
    BOOST_CHECK( tp64k < tp16m );
    BOOST_CHECK( tp64k < tp2gm1 );
    BOOST_CHECK( tp64k < tp2g );
    BOOST_CHECK( tp64k < tp3g );
    BOOST_CHECK( tp16m > tp0 );
    BOOST_CHECK( tp16m > tp1 );
    BOOST_CHECK( tp16m > tp256 );
    BOOST_CHECK( tp16m > tp64k );
    BOOST_CHECK( tp16m < tp2gm1 );
    BOOST_CHECK( tp16m < tp2g );
    BOOST_CHECK( tp16m < tp3g );
    BOOST_CHECK( tp2gm1 > tp0 );
    BOOST_CHECK( tp2gm1 > tp1 );
    BOOST_CHECK( tp2gm1 > tp256 );
    BOOST_CHECK( tp2gm1 > tp64k );
    BOOST_CHECK( tp2gm1 > tp16m );
    BOOST_CHECK( tp2gm1 < tp2g );
    BOOST_CHECK( tp2gm1 < tp3g );
    BOOST_CHECK( tp2g > tp0 );
    BOOST_CHECK( tp2g > tp1 );
    BOOST_CHECK( tp2g > tp256 );
    BOOST_CHECK( tp2g > tp64k );
    BOOST_CHECK( tp2g > tp16m );
    BOOST_CHECK( tp2g > tp2gm1 );
    BOOST_CHECK( tp2g < tp3g );
    BOOST_CHECK( tp3g > tp0 );
    BOOST_CHECK( tp3g > tp1 );
    BOOST_CHECK( tp3g > tp256 );
    BOOST_CHECK( tp3g > tp64k );
    BOOST_CHECK( tp3g > tp2gm1 );
    BOOST_CHECK( tp3g > tp2g );
    BOOST_CHECK( tp3g > tp16m );
}

BOOST_AUTO_TEST_CASE( time_point_decisec_test )
{
    time_point_decisec tp0(0);
    BOOST_CHECK_EQUAL( "1970-01-01T00:00:00", tp0.to_iso_string() );
    BOOST_CHECK_EQUAL( "19700101T000000", tp0.to_non_delimited_iso_string() );

    time_point_decisec tp1(1);
    BOOST_CHECK_EQUAL( "1970-01-01T00:00:00.1", tp1.to_iso_string() );
    BOOST_CHECK_EQUAL( "19700101T000000.1", tp1.to_non_delimited_iso_string() );

    time_point_decisec tp10(10);
    BOOST_CHECK_EQUAL( "1970-01-01T00:00:01", tp10.to_iso_string() );
    BOOST_CHECK_EQUAL( "19700101T000001", tp10.to_non_delimited_iso_string() );

    time_point_decisec tp256(0x100);
    BOOST_CHECK_EQUAL( "1970-01-01T00:00:25.6", tp256.to_iso_string() );
    BOOST_CHECK_EQUAL( "19700101T000025.6", tp256.to_non_delimited_iso_string() );

    time_point_decisec tp64k(0x10000);
    BOOST_CHECK_EQUAL( "1970-01-01T01:49:13.6", tp64k.to_iso_string() );
    BOOST_CHECK_EQUAL( "19700101T014913.6", tp64k.to_non_delimited_iso_string() );

    time_point_decisec tp16m(0x1000000);
    BOOST_CHECK_EQUAL( "1970-01-20T10:02:01.6", tp16m.to_iso_string() );
    BOOST_CHECK_EQUAL( "19700120T100201.6", tp16m.to_non_delimited_iso_string() );

    time_point_decisec tp2gm1(0x7fffffffU);
    BOOST_CHECK_EQUAL( "1976-10-21T12:19:24.7", tp2gm1.to_iso_string() );
    BOOST_CHECK_EQUAL( "19761021T121924.7", tp2gm1.to_non_delimited_iso_string() );

    time_point_decisec tp2g(0x80000000U);
    BOOST_CHECK_EQUAL( "1976-10-21T12:19:24.8", tp2g.to_iso_string() );
    BOOST_CHECK_EQUAL( "19761021T121924.8", tp2g.to_non_delimited_iso_string() );

    time_point_decisec tp3g(0xc0000000U);
    if (BOOST_VERSION >= BOOST_VERSION_NUMBER(1,64,0)) {
        BOOST_CHECK_EQUAL( "2072-01-28T16:51:12", tp3g.to_iso_string() );
        BOOST_CHECK_EQUAL( "20720128T165112", tp3g.to_non_delimited_iso_string() );
    }

    BOOST_CHECK( tp0 == time_point_decisec() );
    BOOST_CHECK( tp0 < tp1 );
    BOOST_CHECK( tp0 < tp10 );
    BOOST_CHECK( tp0 < tp256 );
    BOOST_CHECK( tp0 < tp64k );
    BOOST_CHECK( tp0 < tp16m );
    BOOST_CHECK( tp0 < tp2gm1 );
    BOOST_CHECK( tp0 < tp2g );
    BOOST_CHECK( tp0 < tp3g );
    BOOST_CHECK( tp1 > tp0 );
    BOOST_CHECK( tp1 < tp256 );
    BOOST_CHECK( tp1 < tp64k );
    BOOST_CHECK( tp1 < tp16m );
    BOOST_CHECK( tp1 < tp2gm1 );
    BOOST_CHECK( tp1 < tp2g );
    BOOST_CHECK( tp1 < tp3g );
    BOOST_CHECK( tp10 > tp0 );
    BOOST_CHECK( tp10 > tp1 );
    BOOST_CHECK( tp10 < tp256 );
    BOOST_CHECK( tp10 < tp64k );
    BOOST_CHECK( tp10 < tp16m );
    BOOST_CHECK( tp10 < tp2gm1 );
    BOOST_CHECK( tp10 < tp2g );
    BOOST_CHECK( tp10 < tp3g );
    BOOST_CHECK( tp256 > tp0 );
    BOOST_CHECK( tp256 > tp1 );
    BOOST_CHECK( tp256 > tp10 );
    BOOST_CHECK( tp256 < tp64k );
    BOOST_CHECK( tp256 < tp16m );
    BOOST_CHECK( tp256 < tp2gm1 );
    BOOST_CHECK( tp256 < tp2g );
    BOOST_CHECK( tp256 < tp3g );
    BOOST_CHECK( tp64k > tp0 );
    BOOST_CHECK( tp64k > tp1 );
    BOOST_CHECK( tp64k > tp256 );
    BOOST_CHECK( tp64k < tp16m );
    BOOST_CHECK( tp64k < tp2gm1 );
    BOOST_CHECK( tp64k < tp2g );
    BOOST_CHECK( tp64k < tp3g );
    BOOST_CHECK( tp16m > tp0 );
    BOOST_CHECK( tp16m > tp1 );
    BOOST_CHECK( tp16m > tp256 );
    BOOST_CHECK( tp16m > tp64k );
    BOOST_CHECK( tp16m < tp2gm1 );
    BOOST_CHECK( tp16m < tp2g );
    BOOST_CHECK( tp16m < tp3g );
    BOOST_CHECK( tp2gm1 > tp0 );
    BOOST_CHECK( tp2gm1 > tp1 );
    BOOST_CHECK( tp2gm1 > tp256 );
    BOOST_CHECK( tp2gm1 > tp64k );
    BOOST_CHECK( tp2gm1 > tp16m );
    BOOST_CHECK( tp2gm1 < tp2g );
    BOOST_CHECK( tp2gm1 < tp3g );
    BOOST_CHECK( tp2g > tp0 );
    BOOST_CHECK( tp2g > tp1 );
    BOOST_CHECK( tp2g > tp256 );
    BOOST_CHECK( tp2g > tp64k );
    BOOST_CHECK( tp2g > tp16m );
    BOOST_CHECK( tp2g > tp2gm1 );
    BOOST_CHECK( tp2g < tp3g );
    BOOST_CHECK( tp3g > tp0 );
    BOOST_CHECK( tp3g > tp1 );
    BOOST_CHECK( tp3g > tp256 );
    BOOST_CHECK( tp3g > tp64k );
    BOOST_CHECK( tp3g > tp2gm1 );
    BOOST_CHECK( tp3g > tp2g );
    BOOST_CHECK( tp3g > tp16m );

    time_point_sec s(100);
    BOOST_CHECK( tp10 < s );
    BOOST_CHECK( tp10 <= s );
    BOOST_CHECK( s > static_cast<fc::time_point>(tp10) );
    BOOST_CHECK( s >= static_cast<fc::time_point>(tp10) );
}

BOOST_AUTO_TEST_CASE( time_point_to_string_test )
{
    // time_point
    fc::time_point p0(fc::microseconds(1));
    //std::string result = static_cast<std::string>(p0);
    //std::cerr << "Result: " << result << "\n";
    BOOST_CHECK ( static_cast<std::string>(p0) == "1970-01-01T00:00:00.000001");
    // time_point_decisec
    fc::time_point p1( fc::microseconds(100000));
    fc::time_point_decisec d1(p1);
    //result = static_cast<std::string>(p1);
    //std::cerr << "Result: " << result << "\n";
    BOOST_CHECK( static_cast<std::string>(p1) == "1970-01-01T00:00:00.100000" );
    BOOST_CHECK( static_cast<std::string>(d1) == "1970-01-01T00:00:00.1" );
    fc::time_point_sec p3( p1 );
    //result = static_cast<std::string>(p3);
    //std::cerr << "Result: " << result << "\n";
    BOOST_CHECK( static_cast<std::string>(p3) == "1970-01-01T00:00:00" );    

}

BOOST_AUTO_TEST_SUITE_END()
