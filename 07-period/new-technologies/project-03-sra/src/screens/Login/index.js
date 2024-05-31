import styles from "@/screens/Login/styles";
import { Input } from "@/components/Input";
import { Form } from "@/components/Form";
import { Button } from "@/components/Button";
import { Text, View } from "react-native";
import { LoginLayout } from "@/screens/Login/components/LoginLayout";
import { useAppNavigation } from "@/hooks/useAppNavigation";

export function LoginScreen() {
  const { getGoTo } = useAppNavigation();

  return (
    <LoginLayout title="olá, que bom ter você aqui">
      <Form onFinish={(values) => console.log(values)}>
        <Input name="email" type="email" label="e-mail" />
        <Input name="password" type="password" label="senha" />
        <View style={styles.linksContainer}>
          <Text
            style={styles.link}
            onPress={getGoTo("ForgotPassword", { backTo: "Login" })}
          >
            esqueceu a senha? clique aqui
          </Text>
          <Text style={styles.link} onPress={getGoTo("ForgotPassword")}>
            ainda não tem conta? clique aqui
          </Text>
        </View>
        <Button name="submit">entrar</Button>
      </Form>
    </LoginLayout>
  );
}
