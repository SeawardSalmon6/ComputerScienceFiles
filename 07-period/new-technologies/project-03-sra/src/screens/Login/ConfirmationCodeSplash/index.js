import { APP_TYPOGRAPHY } from "@/assets/theme";
import { Button } from "@/components/Button";
import { useAppNavigation } from "@/hooks/useAppNavigation";
import { LoginLayout } from "@/screens/Login/components/LoginLayout";
import styles from "@/screens/Login/styles";
import { Image, Text } from "react-native";

export function ConfirmationSplashScreen() {
  const { getGoTo } = useAppNavigation();

  return (
    <LoginLayout
      title="agora chegou a sua vez"
      showCardIcon={false}
      titleStyle={{ alignSelf: "center" }}
    >
      <Image
        style={{ width: 100, alignSelf: "center", marginBottom: 48 }}
        resizeMode="contain"
        source={require("@/assets/images/srazinho.png")}
      />
      <Text
        style={[
          styles.tip,
          { ...APP_TYPOGRAPHY.largeText, textAlign: "center" },
        ]}
      >
        vem conhecer o app!
      </Text>
      <Button onPress={getGoTo("Login")}>entrar</Button>
    </LoginLayout>
  );
}
