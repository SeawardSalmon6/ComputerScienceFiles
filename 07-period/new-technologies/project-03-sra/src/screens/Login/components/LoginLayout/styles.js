import { APP_COLORS, APP_TYPOGRAPHY } from "@/assets/theme";
import { StyleSheet } from "react-native";

export default StyleSheet.create({
  root: {
    backgroundColor: APP_COLORS.darkBlue,
  },
  contentContainer: {
    position: "relative",
    alignItems: "center",
    justifyContent: "center",
  },
  backButton: {
    alignItems: "center",
    justifyContent: "center",
    position: "absolute",
    top: 40,
    left: 40,
    padding: 8,
  },
  backIcon: {
    width: 21,
  },
  cardContainer: {
    position: "relative",
    maxWidth: 480,
  },
  titleContainer: {
    marginTop: 28,
    marginBottom: 60,
  },
  cardIcon: {
    position: "absolute",
    top: -32,
    width: 80,
    alignSelf: "center",
  },
  sraLogo: {
    alignSelf: "center",
    position: "absolute",
    bottom: -140,
    width: 75,
  },
  errorMessage: {
    ...APP_TYPOGRAPHY.mediumText,
    color: APP_COLORS.red,
    textAlign: "left",
    marginTop: 8,
  },
});
