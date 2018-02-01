/*    Copyright (c) 2010-2018, Delft University of Technology
 *    All rigths reserved
 *
 *    This file is part of the Tudat. Redistribution and use in source and
 *    binary forms, with or without modification, are permitted exclusively
 *    under the terms of the Modified BSD license. You should have received
 *    a copy of the license with this file. If not, please or visit:
 *    http://tudat.tudelft.nl/LICENSE.
 *
 *    Notes
 *      Reference data generated by datcom script written by F. Engelen. Output has been checked
 *      manually.
 *
 */

#define BOOST_TEST_MAIN

#include <limits>
#include <string>

#include <boost/test/floating_point_comparison.hpp>
#include <boost/test/unit_test.hpp>
#include "Tudat/Basics/testMacros.h"
#include "Tudat/InputOutput/matrixTextFileReader.h"

#include "Tudat/InputOutput/basicInputOutput.h"
#include "Tudat/InputOutput/missileDatcomData.h"

namespace tudat
{
namespace unit_tests
{

BOOST_AUTO_TEST_SUITE( test_missile_datcom_data )

BOOST_AUTO_TEST_CASE( testMissileDatcomData )
{
    using namespace input_output;

    // Read and process data file.
    std::string fileLocation = getTudatRootPath( )
            + "InputOutput/UnitTests/inputForBenchMarkMissileDatcomData.dat";
    MissileDatcomData myMissileDatcomData( fileLocation );

    // Set name of file and path to write to and from.
    std::string outputFileName = getTudatRootPath( ) + "InputOutput/UnitTests/bodyTailConfiguration";

    // Write files for coefficients at each angle of attack.
    myMissileDatcomData.writeCoefficientsToFile( outputFileName, 9, 2 );

    // Read benchmark files and check if all entries are equal to those written by DatcomData
    std::string totalPath;
    Eigen::MatrixXd benchmarkFile, tudatFile;

    for ( int i = 0; i < 5; i++ )
    {
        // Read file just written
        totalPath = outputFileName + "_" + std::to_string( i );
        tudatFile = readMatrixFromFile( totalPath );

        // Read benchmark file
        totalPath = getTudatRootPath( ) + "InputOutput/UnitTests/benchmark_"
                + std::to_string( i );
        benchmarkFile = readMatrixFromFile( totalPath );

        // Iterate over all entries and check values.
        for ( int j = 0; j < tudatFile.rows( ); j++ )
        {
            for ( int k = 1; k < tudatFile.cols( ); k++ )
            {
                if ( std::fabs( benchmarkFile( j, k ) ) >
                        std::numeric_limits< double >::epsilon( ) )
                {
                    BOOST_CHECK_CLOSE_FRACTION( tudatFile( j, k ),
                                                benchmarkFile( j, k ),
                                                std::numeric_limits< double >::epsilon( ) );
                }

                else
                {
                    BOOST_CHECK_SMALL( tudatFile( j, k ) - benchmarkFile( j, k ),
                                       std::numeric_limits< double >::epsilon( )  );
                }
            }
        }
    }
}

} // namespace unit_tests
} // namespace tudat

BOOST_AUTO_TEST_SUITE_END( )
