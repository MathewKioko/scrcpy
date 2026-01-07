# GitHub Repository Setup Instructions

## Step 1: Create Repository on GitHub

1. Go to [GitHub.com](https://github.com)
2. Sign in to your MathewKioko account
3. Click the "+" icon in the top right corner
4. Select "New repository"
5. Fill in the repository details:
   - **Repository name**: `scrcpy`
   - **Description**: "MathewKioko's Enhanced scrcpy with advanced features"
   - **Visibility**: Public (recommended)
   - **Initialize this repository with a README**: ❌ Uncheck (we already have one)
   - **Add .gitignore**: None
   - **Choose a license**: Apache License 2.0
6. Click "Create repository"

## Step 2: Push Code to GitHub

Open your terminal/command prompt and navigate to the project directory:

```bash
cd c:/Users/Hp/Downloads/scrcpy-master
```

Then run these commands:

```bash
# Set the remote URL (replace with your actual GitHub username if different)
git remote set-url origin https://github.com/MathewKioko/scrcpy.git

# Push to GitHub
git push -u origin mathew-custom
```

## Step 3: Set Default Branch (Optional)

1. Go to your new repository on GitHub
2. Click on "Settings" (gear icon)
3. In the left sidebar, click "Branches"
4. Under "Default branch", click "Edit"
5. Change the default branch from "main" to "mathew-custom"
6. Click "Update"

## Step 4: Verify Push

After pushing, you should see:
- All files uploaded to GitHub
- The enhanced README.md visible on the repository homepage
- The `mathew-custom` branch as the active branch

## Troubleshooting

### If you get authentication errors:
```bash
# Use HTTPS with personal access token
git remote set-url origin https://<your-token>@github.com/MathewKioko/scrcpy.git

# Or use SSH if you have SSH keys set up
git remote set-url origin git@github.com:MathewKioko/scrcpy.git
```

### If the push fails:
```bash
# Force push (only if you're sure)
git push -u origin mathew-custom --force
```

## What You'll See on GitHub

Once pushed, your repository will contain:
- ✨ Enhanced README with all new features documented
- 🔧 Complete source code with all enhancements
- 📋 Configuration files for customization
- 📚 Comprehensive documentation
- 🎨 Theme and UI enhancement files

The repository will be ready for others to clone, use, and contribute to!