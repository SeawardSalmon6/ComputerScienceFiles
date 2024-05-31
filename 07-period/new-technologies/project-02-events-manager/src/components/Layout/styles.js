import { StyleSheet } from "react-native";
import { AppTheme } from "../../App.theme";

export const styles = StyleSheet.create({
  container: {
    position: "relative",
    flex: 1,
    backgroundColor: AppTheme.backgroundSecondary,
  },
  scrollViewContainer: {
    flexGrow: 1,
    backgroundColor: AppTheme.backgroundPrimary,
  },
});
