# detect-nuget-inspector 2.6.0 repro — .slnx + .vcxproj + NuGet

Minimal reproduction for STGBD bug: `detect-nuget-inspector` 2.6.0 crashes with
`No instances of MSBuild could be detected` when scanning a `.slnx` solution
containing `.vcxproj` projects on a `windows-2022` Azure DevOps agent (VS2022 / MSBuild 17.x).

## Structure

```
SF90.slnx                         ← new XML solution format (replaces .sln)
src/
  SampleApp/SampleApp.vcxproj     ← C++ executable; refs nlohmann.json 3.11.3, spdlog 1.13.0
  SampleLib/SampleLib.vcxproj     ← C++ static lib; refs boost 1.78.0.0, zlib 1.2.11.1
```

## NuGet packages (open source)

| Package | Version |
|---------|---------|
| nlohmann.json | 3.11.3 |
| spdlog | 1.13.0 |
| boost | 1.78.0.0 |
| zlib | 1.2.11.1 |

## Expected Black Duck behavior

- **detect-nuget-inspector 2.6.0**: crashes — `Microsoft.Build.Locator` 1.4.1
  cannot enumerate VS2022 instances on `windows-2022` hosted agent;
  fallback NuGet scanner ignores `*.slnx` (only globs `*.sln`/`*.csproj`)
- **Fixed version**: should resolve all 4 packages into the BOM
