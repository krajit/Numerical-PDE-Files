/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2017 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "fvOptions.H"
#include "simpleControl.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include "addCheckCaseOptions.H"
    #include "setRootCase.H"
    #include "createTime.H"
    #include "createMesh.H"
    simpleControl simple(mesh);
    #include "createFields.H"

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
    Info<< "\nCalculating temperature distribution\n" << endl;
    while (simple.loop())
    {
        Info<< "Time = " << runTime.timeName() << nl << endl;

            fvScalarMatrix TEqn
            (

                - fvm::laplacian(DT, T) 
             
            );

            TEqn.solve();

            runTime.write();
    }

    Info<< "End\n" << endl;
    return 0;
}


// ************************************************************************* //
